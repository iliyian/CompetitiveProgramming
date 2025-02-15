#include <cstring>
#include <iostream>

// using namespace std;
const int N = 5;
struct course {
  char Course_Name[100]; // 课程名称
  float Course_Score;  // 课程分数
};
struct student {
  char name[20];
  course score[3];
};
void find(student *array, char *cour, int n, char *name, float *score) {
  int i, j;
  for (j = 0; j < 3; j++) {
    if (strcmp(cour, array[0].score[j].Course_Name) == 0)
      break;
  }
  *score = array[0].score[j].Course_Score;
  strcpy(name, array[0].name);
  for (int i = 0; i < n; i++) {
    if (*score < array[i].score[j].Course_Score) {
      *score = array[i].score[j].Course_Score;
      strcpy(name, array[i].name);
    }
  }
}
int main() {
  student array[N];
  char coursename[20];
  char name[20];
  float score;
  for (int i = 0; i < N; i++) {
    std::cin >> array[i].name;
    for (int j = 0; j < 3; j++)
      std::cin >> array[i].score[j].Course_Name >> array[i].score[j].Course_Score;
  }
  std::cin >> coursename; // 输入要查找课程的名称
  find(array, coursename, N, name, &score);
  std::cout << name << " " << score;
  return 0;
}