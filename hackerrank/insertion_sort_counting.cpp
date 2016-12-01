/*

insertionsort_counting

int read(int * p, int k) {
  int nrt = 0;
  while (k>0) {
    nrt += p[k];
    k -= (k&(-k));
  }
  return nrt;
}

void update(int * p, int k) {
  while (k <= 10000000) {
    p[k] ++;
    k += (k&(-k));
  }
}

int assign(int k, int * p, int existing) {
  int n = read(p, k); // sum of counts of number which is not bigger than k
  update(p, k);
  return existing - n;
}


int main() {
  int test = 0;
  cin >> test;
  for (int i = 0; i<test; i++) {
    int n = 0;
    long sum = 0l;
    cin >> n;
    int *p = new int[10000001]; // array is too big for stack
    for (int j = 0; j<10000001; j++) {
      p[j] = 0;
    }

    for (int j = 0; j<n; j++) {
      int k = 0;
      cin >> k;
      sum += assign(k, p, j);
    }
    cout << sum << endl;


    delete[] p;
  }
  return 0;
}
*/