#include <cstring>
#include <cmath>

// comparepairsand triples
inline bool leq(int a1, int a2, int b1, int b2) { 
    return(a1 < b1 || a1 == b1 && a2 <= b2); 
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}
    
// radixsort(onepass)
static void radixPass(int* a, int* b, int* r, int n, int K) {
    // countoccurrences
    int* c = new int[K + 1]; // counterarray 
    for (int i = 0; i <= K; i++) c[i] = 0; // reset counters 
    for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums 
    {
        int t = c[i]; c[i] = sum;
        sum += t;
    }

    // sort
    for (int i = 0; i < n; i++)
        b[c[r[a[i]]]++] = a[i];
}

// compute suffix array of s
// requires[n]=s[n+1]=s[n+2]=0,n>=2
void suffixArray(int* s, int* SA, int n, int sigma_size) {

    // initialize
    int n0 = (n + 2) / 3;
    int n1 = (n + 1) / 3;
    int n2 = n / 3;
    int n02 = n0 + n2;

    int* s12 = new int[n02 + 3]; 
    s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;

    int* SA12 = new int[n02 + 3]; 
    SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;

    int* s0 = new int[n0];
    int* SA0 = new int[n0];

    // compute sample
    for(int i = 0, j = 0; i < n + (n0 - n1); i++)
        if (i % 3 != 0) s12[j++] = i; 

    // sort super characters(triples)
    radixPass(s12,  SA12, s+2,n02, sigma_size);
    radixPass(SA12, s12 , s+1,n02, sigma_size);
    radixPass(s12,  SA12, s , n02, sigma_size);
    
    // construct recursive text
    int name= 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02;i++) { 
        if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
            name++; c0 = s[SA12[i]]; c1 = s[SA12[i] + 1];
            c2 = s[SA12[i] + 2];
        }
        if (SA12[i] % 3 == 1) { s12[SA12[i] / 3] = name; } // first half 
        else { s12[SA12[i] / 3 + n0] = name; } // second half 
    } 
    
    if (name < n02) { // recurseif all supercharactersare not unique
        suffixArray(s12, SA12, n02, name);
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    }  else // end of recursion:supercharactersare all unique 
        for (int i = 0; i < n02; i++) SA12[s12[i]- 1] = i;
    
    // construct nonsample in orderof next(nonsample)
    for (int i=0,j=0;i < n02;i++)
        if (SA12[i]< n0) s0[j++]= 3*SA12[i];

    // sort stably by first character
    radixPass(s0,SA0,s, n0, sigma_size);
    
    // merge sample and non sample suffixes 
    for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
        #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
            int i = GetI();
        int j = SA0[p];
        if (SA12[t] < n0 ? // compare 
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]) :
            leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0]))
        { // sample suffix is smaller 
            SA[k] = i; t++; if (t == n02) // done--- only non sample suffixes left 
                for (k++; p < n0; p++, k++)SA[k] = SA0[p];
        } 
        else { // non sample suffix is smaller 
            SA[k] = j; p++; if (p == n0) // done--- only sample suffixes left 
                for (k++; t < n02; t++, k++) 
                    SA[k] = GetI();
        }
    }

    // cleanup
    delete[] s12;
    delete[] SA12;
    delete[] SA0;
    delete[] s0;
}


using namespace std;

int fix(int p) {
    return p - ceil(p / 3.);
}

bool lt(int a1, int b1, int a2, int b2, int a3, int b3) {
    return a1 != b1 ? a1 < b1 : (a2 != b2 ? a2 < b2 : a3 < b3);
}

int count_g[26 + 1];

void counting_sort(int* keys, int* a, int* b, int off, int n, int sigma) {
    //int count[sigma + 1];
    //int count[26*100] = { 0 };
//    int* count_g = new int[sigma + 1];
    memset(count_g, 0, sizeof(int) * (sigma + 1));

    for (int i = 0; i < n; ++i)
        count_g[keys[a[i] + off]]++;
    for (int d = 0, sum = 0; d <= sigma; ++d)
        sum += count_g[d], count_g[d] = sum - count_g[d];
    for (int i = 0; i < n; ++i)
        b[count_g[keys[a[i] + off]]++] = a[i];

  //  delete[] count_g;
}

void sort_triples(int* s, int* p12, int n12, int sigma) {
    //int tmp[n12];
    int* tmp = new int[n12];
    counting_sort(s, p12, tmp, 2, n12, sigma);
    counting_sort(s, tmp, p12, 1, n12, sigma);
    counting_sort(s, p12, tmp, 0, n12, sigma);
    memcpy(p12, tmp, sizeof(int) * n12);

    delete[] tmp;
}

void sort_group0(int* s, int* p0, int n0, int sigma) {
    //int tmp[n0];
    int* tmp = new int[n0];

    counting_sort(s, p0, tmp, 0, n0, sigma);
    memcpy(p0, tmp, sizeof(int) * n0);
    
    delete[] tmp;
}

int assign_names(int* s, int* names, int* p12, int n12) {
    int lex_name = 0, prev[3] = { -1, -1, -1 };
    for (int i = 0; i < n12; ++i) {
        int* curr = &s[p12[i]];
        if (lt(prev[0], curr[0], prev[1], curr[1], prev[2], curr[2]))
            lex_name++;
        memcpy(prev, curr, sizeof(int) * 3);
        names[i] = lex_name;
    }
    return lex_name;
}

void karkkainen_sanders_sa(int* s, int* sa, int n, int sigma) {
    int n0 = (n + 2) / 3, n1 = n0, n2 = n / 3;
    int n12 = n1 + n2;

    // Get the indices of elements in group 0, and in groups 1 and 2
    //int p12[n12];
    int* p12 = new int[n12];

    for (int i = 1, j = 0; j < n12; i += i % 3, j++)
        p12[j] = i;

    // Sort triples of groups 1 and 2
    sort_triples(s, p12, n12, sigma);

    // Assign names to triples in groups 1 and 2
    int name_count;
    int* names = new int[n12];

    name_count = assign_names(s, names, p12, n12);

    // We now proceed to find the relative order of suffixes in groups 1 and 2
    //int sa12[n12 + 2]; 
    int* sa12 = new int [n12 + 2];
    sa12[n12] = sa12[n12 + 1] = -1;

    // If names are not all distinct, find their sorted order recursively
    if (name_count < n12) {
        // Initialize string s12 of size 2n/3 from the lexicographic names
        //int s12[n12 + 3]; 
        int *s12 = new int[n12 + 3];
        s12[n12] = s12[n12 + 1] = s12[n12 + 2] = 0;
        for (int i = 0; i < n12; ++i)
            s12[p12[i] / 3 + (p12[i] % 3 == 1 ? 0 : n1)] = names[i];

        // Call the function recursively on s12
        karkkainen_sanders_sa(s12, sa12, n12, name_count);

        // Get sorted order of groups 1 and 2 from the suffix array of s12
        for (int i = 0; i < n12; ++i)
            p12[i] = (sa12[i] < n1 ? 1 + 3 * sa12[i] : 2 + 3 * (sa12[i] - n1));

        delete[] s12;
    }

    // Assign sa12 from the sorted order of suffixes
    for (int i = 0; i < n12; ++i)
        sa12[fix(p12[i])] = i;

    // Next step is sorting the suffixes in group 0
    //int p0[n0];

    int *p0 = new int[n0];

    // Order in S(i+1) is implicit from sa12
    for (int i = 0, j = 0; j < n0; ++i) if (p12[i] % 3 == 1)
        p0[j++] = p12[i] - 1;

    // Sort suffixes in group 0
    sort_group0(s, p0, n0, sigma);

    // We now proceed for the merge step
    int i = 0, i0 = 0, i12 = (n % 3 == 1 ? 1 : 0);
    int a1 = -1, a2 = -1, a3 = -1, b1 = -1, b2 = -1, b3 = -1;
    // Compare suffixes in group 0 against groups 1 and 2
    while (i0 < n0 && i12 < n12) {
        // Comparison to suffix in group 1
        if (p12[i12] % 3 == 1) {
            a1 = s[p0[i0]], a2 = sa12[fix(p0[i0] + 1)];
            b1 = s[p12[i12]], b2 = sa12[fix(p12[i12] + 1)];
        }
        // Comparison to suffix in group 2
        else {
            a1 = s[p0[i0]], a2 = s[p0[i0] + 1], a3 = sa12[fix(p0[i0] + 2)];
            b1 = s[p12[i12]], b2 = s[p12[i12] + 1], b3 = sa12[fix(p12[i12] + 2)];
        }
        sa[i++] = lt(a1, b1, a2, b2, a3, b3) ? p0[i0++] : p12[i12++];
    }
    // Copy the remaining suffixes
    for (; i0 < n0; ++i0) sa[i++] = p0[i0];
    for (; i12 < n12; ++i12) sa[i++] = p12[i12];

    delete[] p12;
    delete[] names;
    delete[] sa12;
    delete[] p0;
}