import pygame
import sys
import random

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
PADDLE_WIDTH = 20
PADDLE_HEIGHT = 100
BALL_SIZE = 20
BRICK_WIDTH = 40
BRICK_HEIGHT = 20
BRICK_COLUMNS = 5
BRICK_ROWS = 30  # 600 / 20 = 30 rows to span screen height
PADDLE_SPEED = 5
BALL_SPEED = 5
TARGET_SCORE = 50

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 100, 100)
GREEN = (100, 255, 100)
BLUE = (100, 100, 255)

# Set up display
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Break-Pong")
clock = pygame.time.Clock()

# Paddle class
class Paddle:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.width = PADDLE_WIDTH
        self.height = PADDLE_HEIGHT
        self.speed = PADDLE_SPEED

    def move(self, up=True):
        if up:
            self.y -= self.speed
        else:
            self.y += self.speed
        # Keep paddle within screen bounds
        self.y = max(0, min(SCREEN_HEIGHT - self.height, self.y))

    def draw(self):
        pygame.draw.rect(screen, WHITE, (self.x, self.y, self.width, self.height))

# Ball class
class Ball:
    def __init__(self):
        self.reset()
        self.size = BALL_SIZE

    def move(self):
        self.x += self.vel_x
        self.y += self.vel_y

    def reset(self):
        self.x = SCREEN_WIDTH // 2
        self.y = SCREEN_HEIGHT // 2
        self.vel_x = random.choice([-1, 1]) * BALL_SPEED
        self.vel_y = random.choice([-1, 1]) * BALL_SPEED
        self.last_hit = None  # Tracks which paddle last hit the ball

    def draw(self):
        pygame.draw.circle(screen, WHITE, (int(self.x), int(self.y)), self.size // 2)

# Brick class
class Brick:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.width = BRICK_WIDTH
        self.height = BRICK_HEIGHT
        self.color = random.choice([RED, GREEN, BLUE])
        self.intact = True

    def draw(self):
        if self.intact:
            pygame.draw.rect(screen, self.color, (self.x, self.y, self.width, self.height))

# Particle class for visual effects
class Particle:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.size = random.randint(2, 5)
        self.vel_x = random.uniform(-2, 2)
        self.vel_y = random.uniform(-2, 2)
        self.life = 30  # Frames until particle disappears
        self.color = random.choice([RED, GREEN, BLUE])

    def update(self):
        self.x += self.vel_x
        self.y += self.vel_y
        self.life -= 1

    def draw(self):
        if self.life > 0:
            alpha = int((self.life / 30) * 255)  # Fade out effect
            surface = pygame.Surface((self.size, self.size), pygame.SRCALPHA)
            pygame.draw.circle(surface, (*self.color, alpha), (self.size // 2, self.size // 2), self.size // 2)
            screen.blit(surface, (int(self.x), int(self.y)))

# Collision detection functions
def ball_collides_with_paddle(ball, paddle):
    return (ball.x - ball.size // 2 < paddle.x + paddle.width and
            ball.x + ball.size // 2 > paddle.x and
            ball.y - ball.size // 2 < paddle.y + paddle.height and
            ball.y + ball.size // 2 > paddle.y)

def ball_collides_with_brick(ball, brick):
    if not brick.intact:
        return False
    return (ball.x - ball.size // 2 < brick.x + brick.width and
            ball.x + ball.size // 2 > brick.x and
            ball.y - ball.size // 2 < brick.y + brick.height and
            ball.y + ball.size // 2 > brick.y)

# Initialize game objects
left_paddle = Paddle(50, SCREEN_HEIGHT // 2 - PADDLE_HEIGHT // 2)
right_paddle = Paddle(SCREEN_WIDTH - 50 - PADDLE_WIDTH, SCREEN_HEIGHT // 2 - PADDLE_HEIGHT // 2)
ball = Ball()

# Create central brick wall
bricks = []
brick_start_x = SCREEN_WIDTH // 2 - (BRICK_COLUMNS * BRICK_WIDTH) // 2
for col in range(BRICK_COLUMNS):
    for row in range(BRICK_ROWS):
        bricks.append(Brick(brick_start_x + col * BRICK_WIDTH, row * BRICK_HEIGHT))

# Scores and particles
left_score = 0
right_score = 0
particles = []

# Game loop
running = True
while running:
    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Paddle movement
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        left_paddle.move(up=True)
    if keys[pygame.K_s]:
        left_paddle.move(up=False)
    if keys[pygame.K_UP]:
        right_paddle.move(up=True)
    if keys[pygame.K_DOWN]:
        right_paddle.move(up=False)

    # Update ball
    ball.move()

    # Ball collisions with top/bottom walls
    if ball.y - ball.size // 2 <= 0 or ball.y + ball.size // 2 >= SCREEN_HEIGHT:
        ball.vel_y = -ball.vel_y

    # Ball collisions with paddles
    if ball_collides_with_paddle(ball, left_paddle):
        ball.vel_x = abs(ball.vel_x)  # Ensure ball moves right
        ball.last_hit = 'left'
    elif ball_collides_with_paddle(ball, right_paddle):
        ball.vel_x = -abs(ball.vel_x)  # Ensure ball moves left
        ball.last_hit = 'right'

    # Ball collisions with bricks
    for brick in bricks:
        if ball_collides_with_brick(ball, brick):
            brick.intact = False
            ball.vel_x = -ball.vel_x
            # Add particles
            for _ in range(5):
                particles.append(Particle(brick.x + brick.width // 2, brick.y + brick.height // 2))
            # Award points
            if ball.last_hit == 'left':
                left_score += 1
            elif ball.last_hit == 'right':
                right_score += 1

    # Ball off screen
    if ball.x - ball.size // 2 <= 0:
        right_score += 5
        ball.reset()
    elif ball.x + ball.size // 2 >= SCREEN_WIDTH:
        left_score += 5
        ball.reset()

    # Update particles
    for particle in particles[:]:
        particle.update()
        if particle.life <= 0:
            particles.remove(particle)

    # Draw everything
    screen.fill(BLACK)
    for brick in bricks:
        brick.draw()
    left_paddle.draw()
    right_paddle.draw()
    ball.draw()
    for particle in particles:
        particle.draw()

    # Draw scores
    font = pygame.font.Font(None, 36)
    left_text = font.render(f"Left: {left_score}", True, WHITE)
    right_text = font.render(f"Right: {right_score}", True, WHITE)
    screen.blit(left_text, (50, 20))
    screen.blit(right_text, (SCREEN_WIDTH - 150, 20))

    # Check for game over
    if left_score >= TARGET_SCORE or right_score >= TARGET_SCORE:
        winner = "Left" if left_score >= TARGET_SCORE else "Right"
        game_over_text = font.render(f"{winner} Wins!", True, WHITE)
        screen.blit(game_over_text, (SCREEN_WIDTH // 2 - 50, SCREEN_HEIGHT // 2))
        pygame.display.flip()
        pygame.time.wait(3000)
        running = False

    pygame.display.flip()
    clock.tick(60)

# Cleanup
pygame.quit()
sys.exit()