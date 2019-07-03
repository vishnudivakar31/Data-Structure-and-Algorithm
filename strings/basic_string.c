#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CHAR 50
#define CASE_CONSTANT 32
#define UPPERCASE_LOWEST 65
#define UPPERCASE_HIGHEST 90
#define LOWERCASE_LOWEST 97
#define LOWERCASE_HIGHEST 122
#define NUMBER_0 48
#define NUMBER_9 57

int len(char *name) {
  int i;
  for(i = 0; name[i] != '\0'; i++);
  return i - 1;
}

char * toLowerCase(char *name) {
  int i;
  for(i = 0; name[i] != '\0'; i++) {
    if(name[i] >=65 && name[i] <= 90) {
        name[i] += CASE_CONSTANT;
    }
  }
  return name;
}

char * toUpperCase(char *name) {
  int i;
  for(i = 0; name[i] != '\0'; i++) {
    if(name[i] >=97 && name[i] <= 122) {
        name[i] -= CASE_CONSTANT;
    }
  }
  return name;
}

void countCharacters(char *name) {
  int i, vowelCount = 0, spaceCount = 0, consonantCount = 0;
  for(i = 0; name[i] != '\0'; i++) {
    if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' ||
       name[i] == 'u' || name[i] == 'A' || name[i] == 'E' || name[i] == 'I' ||
       name[i] == 'O' || name[i] == 'U') {
         vowelCount++;
       } else if(name[i] == ' ') {
         spaceCount++;
       } else if(name[i] != '\n'){
         consonantCount++;
       }
  }
  printf("Vowels count: %d.\n", vowelCount);
  printf("Consonant count: %d.\n", consonantCount);
  printf("Spaces count: %d.\n", spaceCount);
  printf("Total characters count including space is %d.\n", i - 1);
}

// int isStringValid(char *name) {
//   int i;
//   for(i = 0; name[i] != '\0'; i++) {
//     if(!(name[i] >= UPPERCASE_LOWEST && name[i] <= UPPERCASE_HIGHEST) &&
//        !(name[i] >= LOWERCASE_LOWEST && name[i] <= LOWERCASE_HIGHEST) &&
//        !(name[i] >= 48 && name[i] <= 57)) {
//          return -1;
//        }
//   }
//   return 0;
// }

char * reverseString(char *name) {
  int length = len(name), i = 0, j = length - 1;
  char *result = (char *) malloc(MAX_CHAR);
  while (i < j) {
    result[i] = name[j];
    result[j] = name[i];
    i++;
    j--;
  }
  result[length] = '\0';
  return result;
}

int compare(char *str1, char *str2) {
  if(len(str1) != len(str2)) {
    return -1;
  }
  int i;
  for(i = 0; str1[i] != '\0'; i++) {
    if(str1[i] != str2[i]) {
      return -1;
    }
  }
  return 0;
}

int isPalindrome(char *name) {
  int i = 0, j = len(name) - 1;
  char *temp = toLowerCase(name);
  while(i < j) {
    if(temp[i] != temp[j]) {
      return -1;
    }
    i++;
    j--;
  }
  return 0;
}

void duplicateCharacters(char *name) {
  char *temp = toLowerCase(name);
  int *hash = (int *) calloc(27, sizeof(int)), i = 0;
  for(; temp[i] != '\0'; i++) {
    hash[temp[i] - 97] += 1;
  }
  for(i = 0; i < 27; i++) {
    if(hash[i] > 0) {
        printf("Duplicate item %c, repeated: %d.\n", (i + 97), hash[i]);
    }
  }
  free(hash);
}

void duplicateCharactersUsingBits(char *name) {
  char *temp = toLowerCase(name);
  long result = 0, mask, i;
  for(i = 0; temp[i] != '\0'; i++) {
    mask = 1;
    mask = mask<<temp[i] - 97;
    if((result & mask) > 0) {
      printf("Duplicate Item: %c.\n", temp[i]);
    } else {
      result = result | mask;
    }
  }
}

int isAnagram(char *str1, char *str2) {
  if(len(str1) != len(str2)) {
    return -1;
  }
  int i, temp[27] = {0};
  char *result1 = toLowerCase(str1), *result2 = toLowerCase(str2);
  for(i = 0; result1[i] != '\0'; i++) {
    temp[result1[i] - 97] += 1;
    temp[result2[i] - 97] -= 1;
  }
  for(i = 0; i < 27; i++) {
    if(temp[i] != 0) {
      return -1;
    }
  }
  return 0;
}

void permUsingBackTracking(char *str, int k) {
  static int a[10] = {0};
  static char result[10];
  int i;

  if(str[k] == '\0') {
      result[k] = '\0';
      printf("%s\n", result);
  } else {
    for(i = 0; str[i] != '\0'; i++) {
      if(a[i] == 0) {
        a[i] = 1;
        result[k] = str[i];
        permUsingBackTracking(str, k + 1);
        a[i] = 0;
      }
    }
  }
}

void perm(char *s, int l, int h) {
  int i;
  char temp;
  if(l == h) {
    printf("%s\n", s);
  } else {
    for(i = l; i <= h; i++) {
      temp = s[i];
      s[i] = s[l];
      s[l] = temp;

      perm(s, l + 1, h);

      temp = s[i];
      s[i] = s[l];
      s[l] = temp;
    }
  }
}

int main() {
  char name[MAX_CHAR];
  printf("Enter your name: ");
  fgets(name, MAX_CHAR, stdin);

  perm(name, 0, len(name) - 1);
  return 0;
}
