import cv2
import numpy as np
from scipy.signal import wiener

def gaussian_kernel(size, sigma):
    k = cv2.getGaussianKernel(size, sigma)
    kernel = np.outer(k, k)
    return kernel

def wiener_deconvolution(blurred, kernel, noise_power=0.000005):
    kernel /= np.sum(kernel)
    
    img_fft = np.fft.fft2(blurred)
    kernel_fft = np.fft.fft2(kernel, s=blurred.shape)
    
    kernel_fft_conj = np.conj(kernel_fft)
    denominator = kernel_fft * kernel_fft_conj + noise_power
    result_fft = (img_fft * kernel_fft_conj) / denominator
    
    result = np.fft.ifft2(result_fft).real
    return np.clip(result, 0, 255).astype(np.uint8)

def deblur_image(path, kernel_size, sigma):
    blurred = cv2.imread(path, cv2.IMREAD_GRAYSCALE)
    
    kernel = gaussian_kernel(kernel_size, sigma)
    deblurred = wiener_deconvolution(blurred, kernel)

    cv2.imwrite("deblurred.png", deblurred)

deblur_image("blurred.png", 25, 7)