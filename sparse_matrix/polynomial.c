#include<stdio.h>
#include<stdlib.h>

struct Term {
  int coef;
  int power;
};

struct Poly {
  int size;
  struct Term *term;
};

int powerOf(int base, int power) {
  int i = power, result = 1;
  while(i > 0) {
    result *= base;
    i--;
  }
  return result;
}

void initialize(struct Poly *p, int size) {
  p->size = size;
  p->term = (struct Term *) malloc(size * sizeof(struct Term));
}

void createPoly(struct Poly *p, int coef, int power, int index) {
  p->term[index].coef = coef;
  p->term[index].power = power;
}

int evaluate(struct Poly *p, int x) {
  int sum = 0, i;
  for(i = 0; i < p->size; i++) {
    sum += (p->term[i].coef) * (powerOf(x, p->term[i].power));
  }
  return sum;
}

void display(struct Poly *p) {
  int i;
  for(i = 0; i < p->size - 1; i++) {
    printf("(%dx^%d) + ", p->term[i].coef, p->term[i].power);
  }
  printf("(%dx^%d)\n", p->term[i].coef, p->term[i].power);
}

struct Poly add(struct Poly *p1, struct Poly *p2) {
  int i = 0, j = 0, k = 0;
  struct Poly result;
  struct Term *terms = (struct Term *) malloc(sizeof(struct Term));
  while(i < p1->size && j < p2->size) {
    terms = (struct Term *) realloc(terms, (k + 1) * sizeof(struct Term));
    if(p1->term[i].power > p2->term[j].power) {
      terms[k++] = p1->term[i++];
    } else if(p2->term[j].power > p1->term[i].power) {
      terms[k++] = p2->term[j++];
    } else {
      terms[k].coef = p1->term[i].coef + p2->term[j].coef;
      terms[k].power = p1->term[i].power;
      k++;
      i++;
      j++;
    }
  }
  for(; i < p1->size; i++) {
    terms = (struct Term *) realloc(terms, (k + 1) * sizeof(struct Term));
    terms[k++] = p1->term[i];
  }
  for(; j < p2->size; j++) {
    terms = (struct Term *) realloc(terms, (k + 1) * sizeof(struct Term));
    terms[k++] = p2->term[j];
  }
  result.size = k;
  result.term = terms;
  return result;
}

void destory(struct Poly *p) {
  free(p->term);
  free(p);
}

int main() {
  struct Poly p1, p2, result;
  int size, i, coef, power, x;

  printf("Enter the no. of terms: ");
  scanf("%d", &size);
  initialize(&p1, size);

  for(i = 0; i < size; i++) {
    printf("Coef for term %d: ", i + 1);
    scanf("%d", &coef);
    printf("Power for term %d: ", i + 1);
    scanf("%d", &power);
    createPoly(&p1, coef, power, i);
  }

  printf("***** Polynomial 1 *****\n");
  display(&p1);

  /***************************/
  printf("Enter the no. of terms: ");
  scanf("%d", &size);
  initialize(&p2, size);

  for(i = 0; i < size; i++) {
    printf("Coef for term %d: ", i + 1);
    scanf("%d", &coef);
    printf("Power for term %d: ", i + 1);
    scanf("%d", &power);
    createPoly(&p2, coef, power, i);
  }

  printf("***** Polynomial 2 *****\n");
  display(&p2);
  /***************************/

  result = add(&p1, &p2);
  printf("***** RESULT *****\n");
  display(&result);

  return 0;
}
