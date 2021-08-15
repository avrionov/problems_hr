#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <functional>
#include <bitset>

#include <fstream>

#include <chrono> 
#include "utils.h"

using namespace std::chrono;


#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif


//-----------------------------------------------------------------------------
unsigned long flippingBits(unsigned long n) {

    unsigned long ret = n;
    // Inverting the bits one by one 
    for (int i = 0; i <= 31; i++) {
        unsigned long mask = (1 << i);
        ret = (ret ^ mask);
    }

    return ret;
}


//-----------------------------------------------------------------------------
void lonely_integer() {
  int n;

  cin >> n;

  int accum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    accum ^= a;
  }

  cout << accum;
}

//-----------------------------------------------------------------------------
void maximum_xor() {
  int l, r;

  cin >> l >> r;

  int max = 0;
  int cnt = 0;
  for (int xorRes = l^r; xorRes; xorRes >>= 1) {
    max |= (1 << cnt++);
  }

  cout << max << endl;
}

//-----------------------------------------------------------------------------
bool is_power_of_2(uint64 n) {
  return !(n == 0) && !(n & (n - 1));
}

int number_of_bits (uint64 n) {
  int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}


void counter_game() {

  int t;
  uint64 n;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    
    if (number_of_bits(n - 1) & 1)
      cout << "Louise" << endl;
    else
      cout << "Richard" << endl;
  }
}

//-----------------------------------------------------------------------------
long long get_nt_xor(long long x) {
  if (x == 0)
    return 0;

  if (x % 4 == 3)
    return 0;

  return get_nt_xor(x - 1) ^ x;
}

long long xor_seq_helper(long long x) {
  long long a = x % 8;
  if (a == 0 || a == 1) return x;
  if (a == 2 || a == 3) return 2;
  if (a == 4 || a == 5) return x + 2;
  if (a == 6 || a == 7) return 0;
  return 0;
}

void xor_sequence() {
  /*int a = 0;
  for (int i = 1; i < 100; i++) {
    cout << (i-1) << " : " << a << " "<< get_nt_xor(i-1) << " " << xor_seq_helper(i-1) << endl;
    a = a ^ i;

  }*/
 

  int t;  // number of test cases
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long int l, r, sum_g;
    cin >> l >> r;

    sum_g = xor_seq_helper (r)  ^ xor_seq_helper (l - 1);
    
    cout << sum_g << endl;
  }
}


//-----------------------------------------------------------------------------
long sumXor(long n) {

	int count = 0;

	while (n) {
		if (n % 2 == 0)
			count++;
		n /= 2;
	}

	return pow(2, count);
}

//-----------------------------------------------------------------------------
void xor_and_sum() {
    const unsigned mod = 1000000007U;
    const unsigned top = 314159U;
    const unsigned powtop = 348880127U;

    string sa, sb;
    std::cin >> sa >> sb;
    const size_t na = sa.size(), nb = sb.size();
    vector<int> a(na % 4 + 1, 0), b(nb % 4 + 1, 0);

}

//-----------------------------------------------------------------------------
void hamming_distance() {

    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int m;

    cin >> m;

    for (int k = 0; k < m; k++) {

        string line;
        
        
        char cmd;
        cin >> cmd;

            {
            switch (cmd) {

                case 'C': {
                    //timethis t("C");
                    int l, r;
                    char ch;

                    cin >> l >> r;
                    cin >> ch;

                    l--;
                    r--;

                    for (int i = l; i <= r; ++i)                        
                            s[i] = ch;

                } break;

                case 'S': {
                    //timethis t("S");
                    int l1, r1;
                    int l2, r2;

                    cin >> l1 >> r1;
                    cin >> l2 >> r2;

                    int len1 = r1 - l1 + 1;
                    int len2 = r2 - l2 + 1;
                    
                    string tmp;

                    tmp = s.substr(0, l1 - 1);

                    string s1 = s.substr(l1 - 1, len1);
                    string s2 = s.substr(l2 - 1, len2);

                    string s1_s2;

                    int len_12 = (l2 - 1) - (r1 + 1) + 1;

                    if (len_12 > 0)
                        s1_s2 = s.substr(r1 + 1 - 1, len_12);

                    
                    tmp += s2;
                    tmp += s1_s2;
                    tmp += s1;

                    int len_r_end = n - (r2 + 1) + 1;
                    if (len_r_end > 0) {
                        string r_end = s.substr(r2 + 1 - 1, len_r_end);
                        tmp += r_end;
                    }

                    s = tmp;
                    
                } break;

                case 'R': {
                    timethis t("R");
                    int r, l;
                  
                    cin >> l >> r;

                    int half = (r - l) / 2 + (r - l) % 2;

                    int pos1 = l - 1;
                    int pos2 = r - 1;
                    for (int i = 0; i < half; ++i, ++pos1, --pos2) {
                        swap(s[pos1], s[pos2]);
                    }
                } break;

                case 'W': {
                    int l, r;

                    cin >> l >> r;
                    for (int i = l-1; i <= r-1; ++i)
                        cout << s[i];
                    cout << endl;

                } break;

                case 'H': {
                    timethis t("H");
                    int l1, l2, len;
                    cin >> l1 >> l2 >> len;

                    int diff = 0;
                    if (l1 != l2) {
                        int pos1 = l1 - 1;
                        int pos2 = l2 - 1;
                        for (int i = 0; i < len; ++i, ++pos1, ++pos2)
                            if (s[pos1] != s[pos2])
                                diff++;
                    }
                        

                    cout << diff << endl;
                } break;
                    
            }
        }
        
    }
}

inline void copy_ar(vector<char>& ar1, vector<char>& ar2, int& start, int l, int r) {
    int len = r - l;

    if (len > 0) {
        auto pos1 = ar1.data() + start;
        auto pos2 = ar2.data() + l;

        memcpy(pos1, pos2, len);
                
        //for (int i = 0; i < len; ++i, ++pos1, ++pos2)
        //    *pos1 = *pos2;
    }

    start += len;
}

inline void copy_ar(vector<int>& ar1, vector<int>& ar2, int& start, int l, int r) {
    int len = r - l;

    if (len > 0) {
        auto pos1 = ar1.data() + start;
        auto pos2 = ar2.data() + l;

        memcpy(pos1, pos2, len * sizeof( int) );

        //for (int i = 0; i < len; ++i, ++pos1, ++pos2)
        //    *pos1 = *pos2;
    }

    start += len;
}

void hamming_distance2() {

    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int m;
    string s1;
    vector<int> s;
    vector<int> tmp;

    {
        timethis t("I");
    
        cin >> s1;
            
        cin >> m;

         s.assign(s1.begin(), s1.end());

        replace(s.begin(), s.end(), 'a', char(0));
        replace(s.begin(), s.end(), 'b', char(1));

        //--------------------------------------------------------------------
        tmp.resize(s.size());
    }
    

    for (int k = 0; k < m; k++) {
        
        char cmd;
        cin >> cmd;
        {
            switch (cmd) {

            case 'C': {
                timethis t("C");
                int l, r;
                char ch;

                cin >> l >> r;
                cin >> ch;

                l--;
                r;
                
                fill(s.begin() + l, s.begin() + r, ch-'a');

            } break;

            case 'S': {
                //timethis t("S");
                int l1, r1;
                int l2, r2;

                cin >> l1 >> r1;
                cin >> l2 >> r2;

                int len1 = r1 - l1 + 1;
                int len2 = r2 - l2 + 1;
                
                //-------------------------------------------
                int start = 0;
                int len_12 = (l2 - 1) - (r1 + 1) + 1;

                copy_ar(tmp, s, start, 0, l1 - 1);
                copy_ar(tmp, s, start, l2-1, l2-1 + len2);

                copy_ar(tmp, s, start, (r1 + 1) - 1, (r1 + 1) - 1 + len_12);
                
                int len_r_end = n - (r2 + 1) + 1;
                copy_ar(tmp, s, start, l1 - 1, l1 - 1 + len1);
                if (len_r_end > 0) {
                    copy_ar(tmp, s, start, + r2 + 1 - 1, s.size());
                    
                }

                swap(s, tmp);
                
            } break;

            case 'R': {
                //timethis t("R");
                int r, l;

                cin >> l >> r;
                 
                int half = (r - l) / 2 + (r - l) % 2;

                //int pos1 = l - 1;
                //int pos2 = r - 1;

                auto pos1 = s.data() + l -1;
                auto pos2 = s.data() + r -1;
                auto end_pos1 = pos1 + half;

                for (; pos1  < end_pos1; ++pos1, --pos2) {
                    swap(*pos1, *pos2);
                }

                //reverse(s.begin() + pos1, s.begin() + pos2);

            } break;

            case 'W': {
                timethis t("W");
                int l, r;

                cin >> l >> r;
                --l;
                --r;
                for (int i = l; i <= r; ++i)
                    cout << char(s[i] + 'a');
                cout << endl;

            } break;

            case 'H': {
                timethis t("H");
                int l1, l2, len;
                cin >> l1 >> l2 >> len;

                if (l1 > l2)
                    swap(l1, l2);

                int diff = 0;
                if (l1 != l2) {
                    //int pos1 = l1 - 1;
                    //int pos2 = l2 - 1;

                    
                    auto  register pos1 = s.begin() + l1 - 1;
                    auto  register pos2 = s.begin() + l2 - 1;

                    //auto  pos1 = s.data() + l1 - 1;
                    //auto  pos2 = s.data() + l2 - 1;

                    auto pos1_end = pos1 + len;                    
                    for (; pos1 < pos1_end; ++pos1, ++pos2)                        
                        diff += (*pos1 ^ *pos2);
                    
                                        
                    /*
                    auto  pos1 = s.data() + l1 - 1;
                    auto  pos2 = s.data() + l2 - 1;
                    for (int i = 0; i < len; ++i)
                        diff += pos1[i] ^ pos2[i];
                        */
                }
                
                cout << diff << endl;
            } break;

            }
        }

    }

    timethis::print_stats();
}

typedef unsigned long long int uint64;

const int MAX_N = 50000;
const int BASE = 64;
const int SIZE_B = (MAX_N + 63) / BASE; 

class bit_set;

void print_bitset(bit_set& bts, int l, int r);

uint64 rev(uint64 x)
{
    x = (x & 0xaaaaaaaaaaaaaaaaull) >> 1 | (x & 0x5555555555555555ull) << 1;
    x = (x & 0xccccccccccccccccull) >> 2 | (x & 0x3333333333333333ull) << 2;
    x = (x & 0xf0f0f0f0f0f0f0f0ull) >> 4 | (x & 0x0f0f0f0f0f0f0f0full) << 4;
    x = (x & 0xff00ff00ff00ff00ull) >> 8 | (x & 0x00ff00ff00ff00ffull) << 8;
    x = (x & 0xffff0000ffff0000ull) >> 16 | (x & 0x0000ffff0000ffffull) << 16;
    return x >> 32 | x << 32;
}


class bit_set {

public:
    bit_set() {
        
        for (int i = 0; i < SIZE_B; i++)
            _buf[i] = 0;
    }

    ~bit_set() {        
    }

    void flip(int i) { 
        _buf[i >> 6] ^= 1ull << (i & 63);
    }

    int get(int i) const { 
        return _buf[i >> 6] >> (i & 63) & 1;
    }

    void set(int i, int v) {     
        if (v == 1)
            _buf[i >> 6] |= 1ull << (i & 63);
        else
            _buf[i >> 6] &= ~(1ull << (i & 63));

        //if (get(i) != v) 
        //    flip(i);
    }

    void fill(int l, int r, int v) {
        
        for (int i = l; i < r; )
            if (i & 63 || i + 63 >= r) {
                set(i, v);
                i++;
            } else {
                _buf[i >> 6] = v ? -1ull : 0;
                i += 64;
            }
    }

    void copy(const bit_set& o, int l, int r, int to) {
        int shift = to - l;
        for (int i = l; i < r; )
            if (i & 63 || i + 63 >= r) {
                set(i + shift, o.get(i));
                i++;
            }
            else {
                word(i + shift, o._buf[i >> 6]);
                i += 64;
            }
    }

    void swap(bit_set& ar) {
        ::swap(_buf, ar._buf);
    }

    void word(int i, uint64 w) {

        int j = i >> 6;
        _buf[j] |= w << (i & 63);
        i += 63;
        j = i >> 6;

        if (j < SIZE_B)
            _buf[j] |= (w >> 63) - (i & 63);
    }


    void reverse(int l, int r) {

        bit_set t = *this;
        fill(l, r, 0);
        for (int i = l; i < r; )
            if (i & 63 || i + 63 >= r) {
                set(r - 1 - (i - l), t.get(i));
                i++;
            }
            else {
                word(r - 64 - (i - l), rev(t._buf[i >> 6]));
                i += 64;
            }
    }

    bit_set operator^(const bit_set& in) const {
        bit_set result;

        for (int i = 0; i < SIZE_B; i++)
            result._buf[i] = _buf[i] ^ in._buf[i];

        return result;
    }


    bit_set shift_right(int i) {
        bit_set ret;
        int o = i & 63;
        int shift = i / 64;

        if (!o) {
            for (int i = 0; i < SIZE_B - shift; i++)
                ret._buf[i] = _buf[i + shift];
        } else {
            for (int i = 0; i < SIZE_B - shift - 1; i++)            
                ret._buf[i] = (+_buf[i + shift] >> o) | ((_buf[i + shift + 1] << 64) - o);
            ret._buf[SIZE_B - shift - 1] = _buf[SIZE_B - 1] >> o;
        }
        return ret;
    }

   uint64 _buf[SIZE_B];
};




void print_bitset(bit_set& bts, int l, int r) {    
    for (int i = l; i < r; ++i)
        cout << char(bts.get(i) + 'a');
    cout << endl;
}


void hamming_distance3() {

    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int m;
    string s1;

    bit_set s, tmp;
    
    {
        timethis t("I");

        cin >> s1;

        cin >> m; 

        for (int i = 0; i < n; i++) {
            if (s1[i] == 'b') {
                s.set(i, 1);                

                for (int j = 0; j <= i; ++j) {
                    if (s.get(i) + 'a' != s1[i])
                        cout << i << endl;
                }
                    
            }
        }
            
       
        print_bitset(s, 0, n);
    }

    for (int k = 0; k < m; k++) {

        char cmd;
        cin >> cmd;
        {
            switch (cmd) {

            case 'C': {
                //timethis t("C");
                int l, r;
                char ch;

                cin >> l >> r;
                cin >> ch;

                l--;
                r;
                s.fill(l, r, ch - 'a');
            } break;

            case 'S': {
                //timethis t("S");
                int l1, r1;
                int l2, r2;

                cin >> l1 >> r1;
                cin >> l2 >> r2;

                int len1 = r1 - l1 + 1;
                int len2 = r2 - l2 + 1;
                
                --l1;
                --l2;

                bit_set tmp;
                tmp = s;

                s.fill(l1, r2, 0);
                s.copy(tmp, l1, r1, r2 - (r1 - l1));
                s.copy(tmp, r1, l2, l1 + (r2 - l2));
                s.copy(tmp, l2, r2, l1);
                
                //print_bitset(s, 0, n);

            } break;

            case 'R': {
                //timethis t("R");
                int r, l;

                cin >> l >> r;
                
                s.reverse(l-1, r);
            } break;

            case 'W': {
                //timethis t("W");
                int l, r;

                cin >> l >> r;
                --l;
                --r;
                for (int i = l; i <= r; ++i)
                    cout << char(s.get(i) + 'a');
                cout << endl;

            } break;

            case 'H': {
                //timethis t("H");
                int l1, l2, len;
                cin >> l1 >> l2 >> len;

                if (l1 > l2)
                    swap(l1, l2);

                int diff = 0;

                --l1;
                --l2;
                bit_set tmp = s ^ s.shift_right(l2 - l1);

                for (int i = l1; i < l1 + len; )
                    if (i & 63 || i + 63 >= l1 + len)
                        diff += tmp.get(i++);
                    else {
                        //diff += __builtin_popcountll(tmp._buf[i >> 6]);
                        diff += __popcnt64(tmp._buf[i >> 6]);
                        i += 64;
                    }

                cout << diff << endl;
            } break;

            }
        }

        //print_bitset(s, 0, n);
    }

    //timethis::print_stats();
}


int gcd(int x, int y) {
    if (x > y) swap(x, y);
    while (x > 0) {
        int z = x;
        x = y % x;
        y = z;
    }
    return y;
}

#define uint unsigned int

int iterate_it_2(vector<int> start) {
        
    set<int> step1s;
    int N = start.size();
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            if (start[i] != start[j])
                step1s.insert(abs(start[i] - start[j]));
    
    start.clear();

    for (auto x : step1s) start.push_back(x);
    N = start.size();

    if (N == 0) {
        return 1;
        
    }

    int g = start[0];
    for (int i = 1; i < N; i++) g = gcd(g, start[i]);
    for (int i = 0; i < N; i++) start[i] /= g;

    int K = 32, M = 200000;
    vector<uint> live(M / K, 0);
    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
        live[(start[j] - start[i] - 1) / K] |= 1 << ((start[j] - start[i] - 1) % K);

    int t = 2, m = start[N - 1] - start[0];

    while (m > 0 && (live[0] & 1) == 0) {
        vector<uint> liveN(M / K, 0);
        bool b = false;
        int m2 = m;
        for (int i = 0; i < m; i++) 
            if ((live[i / K] >> (i % K)) & 1) {
                if (!b) m2 = m - (i + 1);
                b = true;
                if (i % K < 31) 
                    for (int j = i / K; j < M / K; j++) 
                        liveN[j - i / K] |= live[j] >> (i % K + 1);
                for (int j = i / K + 1; j < M / K; j++) 
                    liveN[j - i / K - 1] |= (live[j] << (K - 1 - i % K));
        }
        live = liveN;
        //int p =0;
        //for(int i =0; i < M; i++) if((live[i/K]>>(i%K))&1) p++;
        //cout << t+1 << " " << m2 << " " << p << endl;
        m = m2;
        t++;
    }

    return t + m;    
    return 0;
}


//-----------------------------------------------------------------------------
int iterateIt(int* a, int n) {

    int rep = 0;

    // remove duplicats
    const int K = 32, M = 200000;
    const int SHIFT = 5;
    const int MASK = 31; 

    //vector<int> cleaned;
    int* cleaned = new int[n];
    int cleaned_size = 0;
    {
        //vector<uint> bitfield2(M / K, 0);
        uint bitfield2[M / K] = { 0 };

        {
            timethis t("sort");
            sort(a, a+n);
        }
        
        {
            timethis t("unique");
         //   a.erase(unique(a.begin(), a.end()), a.end());
            int new_n = 0;
            for (int i = 1; i < n-1; i++) {
                if (a[i] != a[i + 1])
                    a[new_n++] = a[i];
            }

            a[new_n++] = a[n - 1];

            n = new_n;
        }

        

        timethis t("init");

        int max_a = 0;
        int min_a = 100001;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int diff = a[j] - a[i];                
                //bitfield2[diff / K] |= 1 << (diff % K);
                bitfield2[diff >> SHIFT ] |= 1 << (diff & MASK);
                max_a = max(max_a, diff);
                min_a = min(min_a, diff);
            }

        for (int i = min_a; i <= max_a; i++)
            if ((bitfield2[i >> SHIFT] >> (i & MASK)) & 1)
            //if ((bitfield2[i / K] >> (i % K)) & 1)
                //cleaned.push_back(i);
                cleaned[cleaned_size++] = i;
    }
    
    rep++;

    if (cleaned_size == 0) return rep;
    //if (cleaned.size() == 0) return rep;
    
    {
        //timethis t("gcd");
        
        int g = cleaned[0];
        for (int i  = 1; i < cleaned_size; ++i)
            g = gcd(g, cleaned[i]);

        for (int i = 0; i < cleaned_size; ++i)
            cleaned[i]= cleaned[i] / g;
    }

    // cout << string("cleaned size: ") << cleaned_size << endl;

    //vector<uint> bitfield(M / K, 0);
    uint bitfield[M / K] = { 0 };

    {
        timethis t("initb");        

        for (int i = 0; i < cleaned_size; ++i) {
            for (int j = i+1; j < cleaned_size; ++j) {
                int diff = cleaned[j] - cleaned[i];                
                //bitfield[(diff - 1) / K] |= 1 << ((diff - 1) % K);
                bitfield[(diff - 1) >> SHIFT] |= 1 << ((diff - 1) &  MASK);
            }
        }
    }
            
    rep++;

    int max_number = cleaned[cleaned_size -1] - cleaned[0];;
    uint tmp_bitfield[M / K] = { 0 };

    while (max_number > 0 && (bitfield[0] & 1) == 0) {
        //vector<uint> tmp_bitfield(M / K, 0);
        
        bool b = false;
        int m2 = max_number;
        for (int i = 0; i < max_number; i++) {
            int i_shift = i >> SHIFT;
            int i_mask = i & MASK;

            if ((bitfield[i_shift] >> (i_mask)) & 1) {

                if (!b)
                    m2 = max_number - (i + 1);

                b = true;

                //if (i % K < 31)
                    for (int j = i / K; j < M / K; j++)
                        //tmp_bitfield[j - i / K] |= bitfield[j] >> (i % K + 1);
                        tmp_bitfield[j - i_shift] |= bitfield[j] >> (i_mask + 1);

                for (int j = i_shift + 1; j < M / K; j++)
                    //tmp_bitfield[j - i / K - 1] |= (bitfield[j] << (K - 1 - i % K));
                    tmp_bitfield[j - i_shift - 1] |= (bitfield[j] << (K - 1 - i_mask));
            }
        }
            //if ((bitfield[i / K] >> (i % K)) & 1) {

            
        //bitfield = tmp_bitfield;        
        swap(bitfield, tmp_bitfield);

        max_number = m2;
        rep ++;

        //cout << rep << endl;
    }

    timethis::print_stats();
    return rep + max_number;    
}

//-----------------------------------------------------------------------------

typedef unsigned char bytet;


void iterateIt_test() {
    //vector<int> a = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
    //vector<int> a_test_4 = { 17, 33, 65, 129, 257, 513, 1025, 2049, 4097, 8193, 16385, 32769 };

    int n;
    cin >> n;

    int* ar = new int[n];


    for (int i = 0; i < n; i++)        
        scanf("%d", &ar[i]);

    int ret = iterateIt(ar, n);

    cout << ret;
}

//-----------------------------------------------------------------------------
uint64 power2(uint64 m) {

    if (m < 1) return 0;

    uint64 res = 1;

    for (uint64 i = 0; i < 8 * sizeof(uint64); i++) {
        uint64 curr = 1ull << i;

        if (curr > m) 
            break;

        res = curr;
    }

    return res;
}

vector<int> xorMatrix(uint64 m, vector<int> first_row) {
 
    m--;

    uint64 n = first_row.size();
    vector<int> a(first_row);
    vector <int> b(n);

    bool pow_reduction = true;

    while (m > 0) {
        uint64 pow2 = power2(m);
        if (pow_reduction) {            
                for (int i = 0; i < n; ++i)
                    b[i] = a[i] ^ a[(i + pow2) % n];
                pow_reduction = !pow_reduction;
        } else {
            for (int i = 0; i < n; ++i)
                a[i] = b[i] ^ b[(i + pow2) % n];
            pow_reduction = !pow_reduction;
        }
        m = m - pow2;
    }    

    if (pow_reduction)
        return a;
    else 
        return b;
}

void test_xorMatrix() {
    uint64 n, m;

    cin >> n >> m;

    vector<int> first_row(n);

    for (int& x : first_row)
        cin >> x;

    vector<int> last_row = xorMatrix(m, first_row);

    for (int x : last_row)
        cout << x << " ";
}

//-----------------------------------------------------------------------------
string table[4] = { "ABCD",
                       "BADC",
                       "CDAB",
                       "DCBA" };


void mixing_proteins() {
    uint64 n, k;

    cin >> n >> k;

    string proteins;

    cin >> proteins;

    string a(proteins);
    string b(proteins);

    bool pow_reduction = true;

    while (k > 0) {
        uint64 pow2 = power2(k);
        if (pow_reduction) {
            for (int i = 0; i < n; ++i)
                b[i] = table[a[i]-'A'][a[(i + pow2) % n] - 'A'];
            pow_reduction = !pow_reduction;
        }
        else {
            for (int i = 0; i < n; ++i)
                a[i] = table[b[i] - 'A'][b[(i + pow2) % n] - 'A'];
            pow_reduction = !pow_reduction;
        }
        k = k - pow2;
    }

    if (pow_reduction)
        cout << a;
    else
        cout << b;   
    
}

//-----------------------------------------------------------------------------    
long xor_sum_sub(int l, int r, vector<long>& a, map<uint64, long>& memo) {

    if (l == r)
        return a[l];

    uint64 index = (((uint64)r) << 32) | (uint64)l;

    auto it = memo.find(index);

    if (it != memo.end())
        return it->second;

    int result = xor_sum_sub(l , r -1, a, memo) ^ a[r];

    memo[index] = result;

    return result;
}

//-----------------------------------------------------------------------------
vector<int> xorSubsequence_old(vector<long> a) {
    int n = a.size();

    map<uint64, long> memo;

    map<long, long> sums;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long xor_sum = xor_sum_sub(i, j, a, memo);
            sums[xor_sum] ++;
        }
    }


    /*
    for (int i = 0; i < n; i++) {
        int xor_sum = a[i];
        sums[xor_sum] ++;
        for (int j = i + 1; j < n; j++) {
            xor_sum = xor_sum ^ a[j];
            sums[xor_sum] ++;
        }
    }*/


   
    int max_count = 0;
    int max_num;

    for (auto a : sums) {
        if (max_count < a.second) {
            max_count = a.second;
            max_num = a.first;
        }
    }

    vector<int> result;

    result.push_back(max_num);
    result.push_back(max_count);

    return result;
}

long index(int i, int j, int n) {
    return i * (n + 1) + j;
}

vector<int> xorSubsequence_old2(vector<long> a) {
    int n = a.size();

    map<long, long> sums;

    long max_num = a[0];

    for (int i = 1; i < n; i++) 
        max_num = max(max_num, a[i]);
    
     int m = (1 << (int)(log2(max_num) + 1)) - 1;

     vector < vector<long>> dp(n + 1, vector<long>(m + 1, 0));
     // The xor of empty subset is 0 
     dp[0][0] = 1;

     // Fill the dp table 
     for (int i = 1; i <= n; i++)
         for (int j = 0; j <= m; j++)
             dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ a[i - 1]];

    int max_count = 0;
    
    
    for (int i = 0; i < m; i++)
        if (max_count < dp[n][i]) {
            max_count = dp[n][i];
            max_num = i;
        }
   
    vector<int> result;

    result.push_back(max_num);
    result.push_back(max_count);

    return result;
}


const int BITS = 16, NUM_SIZE = 1 << BITS;
uint64  counts[NUM_SIZE] = { 0 };

const int ARRSIZE = 100000;
long xr_a[ARRSIZE];
long xr_prev[ARRSIZE];
long xr_stage[ARRSIZE];

void xor_subsequence_test() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        //cin >> a[i];
        scanf("%d", &xr_a[i]);
        xr_prev[i] = xr_a[i];
        counts[xr_a[i]] ++;
    }        

    for (int j = 1; j < n; j++) {
        //cout << j << endl;
        for (int i = 0; i < n - j; i++) {
            xr_stage[i] = xr_prev[i] ^ xr_a[i + j];
            counts[xr_stage[i]] ++;
        }
        swap(xr_prev, xr_stage);
    }

    int max_count = 0;
    int max_num;

    for (int i = 0; i < NUM_SIZE; i++)
        if (max_count < counts[i]) {
            max_count = counts[i];
            max_num = i;
        }

    cout << max_num << " " << max_count;
}

//-----------------------------------------------------------------------------

//#define FOR(i, a, b) for (int i = (a); i < (b); i++)
//#define REP(i, n) for (int i = 0; i < (n); i++)

void walsh_transform()
{
    for (int m = 2; m <= NUM_SIZE; m *= 2) {
        int m_half = m / 2;
        for (int i = 0; i < NUM_SIZE; i += m)
            for (int j = 0; j < m_half; j++) {
                uint64 x = counts[i + j], y = counts[i + j + m_half];
                counts[i + j] = x + y;
                counts[i + j + m_half] = x - y;
        }
    }
}

void  xor_subsequence_test2()
{
    int n;
    cin >> n;
    int acc = 0;

    counts[0]++;
    for (int i = 0; i < n; i++) {    
        int x;
        scanf("%d", &x);

        acc ^= x;
        counts[acc]++;
    }

    walsh_transform();

    for (int i = 0; i < NUM_SIZE; i++)     
        counts[i] *= counts[i];

    walsh_transform();
    for (int i = 0; i < NUM_SIZE; i++) 
        counts[i] /= NUM_SIZE;

    int x;
    uint64 y = 0;
    for (int i = 1; i < NUM_SIZE; i++)
        if (counts[i] > y)
            y = counts[x = i];

    cout << x << " " << y / 2;    
}


//-----------------------------------------------------------------------------
void greater_xor() {

    int q;
    cin >> q;

    while (q) {
        long long int x;
        cin >> x;

        long long int sum = 0;

        int bit_pos = 0;

        while (x) {
            if ((x & 1) == 0)
                sum += (1L << bit_pos);

            bit_pos++;

            x >>= 1;
        }

        cout << sum << endl;
        q--;
    }
}



void xor_key_brute_force() {
    int t;
    cin >> t;

    while (t--) {

        int n, q;
        cin >> n >> q;

        vector<int> ar;
        read_array(ar, n);
        
        while (q--) {
            int a, l, r;

            cin >> a >> l >> r;

            int max_xor = 0;
            for (int i = l - 1; i <= r - 1; i++)
                max_xor = max(max_xor, a ^ ar[i]);

            cout << max_xor << endl;
        }
    }
}


class BigTrie {

public:
    BigTrie() {
        _next = 0;
        _root = _next++;
    }

    int find(int a, int l, int r) {
        return find(a, l, r, _nodes);
    }


    void insert(int a, int ind) {
        insert(a, ind, _nodes);
    }

private:

    const int BITS = 15;

    struct Trie {
        vector<int> indexes;
        int next[2];
    };

    int _next, _root;
    Trie _nodes[100005];

    void digits_array(vector<int>& digits, int a) {

        while (a) {
            digits.push_back(a % 2);
            a /= 2;
        }

        while (digits.size() < BITS)
            digits.push_back(0);

        reverse(digits.begin(), digits.end());
    }

    void insert(int a, int ind, Trie nodes[]) {

        vector<int> digits;

        digits_array(digits, a);

        int curr = _root;
        nodes[curr].indexes.push_back(ind);

        for (int i = 0; i < BITS; i++) {
            int digit = digits[i];

            if (!nodes[curr].next[digit]) {
                nodes[curr].next[digit] = _next++;
            }
            curr = nodes[curr].next[digit];
            nodes[curr].indexes.push_back(ind);
        }
    }

    int find(int a, int l, int r, Trie nodes[]) {

        vector<int> digits;

        digits_array(digits, a);

        int curr = _root;
        int ret = 0;
        for (int i = 0; i < BITS; i++) {
            int x = digits[i];
            if (x == 0) {
                if (nodes[curr].next[1]) {
                    auto& index = nodes[nodes[curr].next[1]].indexes;
                    auto itr = lower_bound(index.begin(), index.end(), l);
                    if (itr != index.end() && *itr <= r) {
                        ret = ret * 2 + 1;
                        curr = nodes[curr].next[1];
                    }
                    else {
                        curr = nodes[curr].next[0];
                        ret *= 2;
                    }
                }
                else {
                    curr = nodes[curr].next[0];
                    ret *= 2;
                }
            }
            else {
                if (nodes[curr].next[0]) {
                    auto& index = nodes[nodes[curr].next[0]].indexes;
                    auto itr = lower_bound(index.begin(), index.end(), l);
                    if (itr != index.end() && *itr <= r) {
                        ret = ret * 2 + 1;
                        curr = nodes[curr].next[0];
                    }
                    else {
                        ret *= 2;
                        curr = nodes[curr].next[1];
                    }
                }
                else {
                    ret *= 2;
                    curr = nodes[curr].next[1];
                }
            }
        }
        return ret;
    }
};

//-----------------------------------------------------------------------------
void xor_key() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        int a;

        //BigTrie trie;
        BigTrie* trie = new BigTrie();

        for (int i = 0; i < n; i++) {
            cin >> a;
            trie->insert(a, i);
        }

        int l, r;
        while (q--) {
            cin >> a >> l >> r;
            //cout << trie.find(a, l - 1, r - 1) << endl;
            printf("%d\n", trie->find(a, l - 1, r - 1));
        }
    }
}

//-----------------------------------------------------------------------------
void sansa_xor() {

    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a;

        vector<int64> ar;
        read_array(ar, n);

        if (n % 2) {
            int64 ret = 0;
            ret = ar[0];
            for (int i = 2; i < n; i += 2) {
                ret ^= ar[i];
            }
            cout << ret << endl;
        } else {
            cout << 0 << endl;         
        }
    }
}

//-----------------------------------------------------------------------------
void lpad_zero(std::string& A, const size_t& max_len)
{
    if (A.length() < max_len) {
        string pad('0', max_len - A.length());
        A = pad + A;
    }
}

int get_hex_char(const char c) { 
    return c >= 'A' ? 10 + c - 'A' : c - '0'; 
}

char set_hex_char(const int i) {
    return static_cast<char>(i < 10 ? '0' + i : 'A' + (i - 10));
}

void ltrim(std::string& s, const char t)
{
    s.erase(0, s.find_first_not_of(t));    
}


bool pass_one_a_or_b(const size_t& max_len, std::string& A, std::string& B, std::string& C, int& k) {

    for (int i = 0; i < max_len; i++) {
        int a = get_hex_char(A[i]);
        int b = get_hex_char(B[i]);
        int c = get_hex_char(C[i]);

        for (int j = 3; j >= 0; j--) {
            int ab = 1 & (a >> j);
            int bb = 1 & (b >> j);
            int cb = 1 & (c >> j);

            int res = (ab << 2) + (bb << 1) + cb;

            switch (res) {
            case 0: // 000
                    // nothing
                break;

            case 1: // 001
                if (k >= 1) {
                    k--;
                    bb = 1;
                    b |= 1 << j;
                    B[i] = set_hex_char(b);
                } else {
                    return false; 
                }                   

                break;

            case 2: // 010
                if (k >= 1) {
                    k--;
                    bb = 0;
                    b &= ~(1 << j);
                    B[i] = set_hex_char(b);
                } else {
                    return false;
                }

                break;

            case 3: // 011
                    // nothing
                break;

            case 4: // 100
                if (k >= 1) {
                    k--;
                    ab = 0;
                    a &= ~(1U << j);
                    A[i] = set_hex_char(a);
                } else {
                    return false;
                }
                break;

            case 5: // 101
                    // nothing, secomd pass 101 -> 011
                break;

            case 6: // 110
                if (k >= 2) {
                    k -= 2;
                    ab = 0;
                    bb = 0;

                    a &= ~(1 << j);
                    A[i] = set_hex_char(a);

                    b &= ~(1 << j);
                    B[i] = set_hex_char(b);
                } else {
                    return false;
                }
                break;

            case 7: // 111
                    // nothing, second pass 111 -> 011
                break;
            }
        }
    }

    return true;
}

void a_or_b() {

    int q;

    cin >> q;

    for (int t = 0; t < q; t++) {
        int k;
        cin >> k;

        string A, B, C;
        cin >> A >> B >> C;
                
        auto max_len = max(A.length(), B.length());
        max_len = max(max_len, C.length());

        lpad_zero(A, max_len);
        lpad_zero(B, max_len);
        lpad_zero(C, max_len);

        bool pass_one = pass_one_a_or_b(max_len, A, B, C, k);

        // second pass
        if (! pass_one ) {
            cout << "-1" << endl;
        } else {
            for (int i = 0; i < max_len; i++) {
                int a = get_hex_char(A[i]);
                int b = get_hex_char(B[i]);
                int c = get_hex_char(C[i]);

                for (int j = 3; j >= 0; j--) {
                    int ab = 1 & (a >> j);
                    int bb = 1 & (b >> j);
                    int cb = 1 & (c >> j);

                    int res = (ab << 2) + (bb << 1) + cb;
                    switch (res) {
                        case 5: // 101
                            if (k >= 2) {
                                // nothing, secomd pass 101 -> 011
                                k -= 2;
                                ab = 0;
                                bb = 1;

                                a &= ~(1 << j);
                                A[i] = set_hex_char(a);

                                b |= 1 << j;
                                B[i] = set_hex_char(b);                                
                            }
                            break;

                        case 7: // 111
                            if (k >= 1) {
                                // nothing first pass, second pass 111 -> 011
                                k -= 1;
                                ab = 0;

                                a &= ~(1 << j);
                                A[i] = set_hex_char(a);
                            }
                            break;
                    }

                    if (k == 0)
                        break;
                }
            }

            ltrim(A, '0');
            ltrim(B, '0');

            if (A.size() == 0)
                A = "0";

            if (B.size() == 0)
                B = "0";

            cout << A << endl;
            cout << B << endl;
        }           
    }
}


//-----------------------------------------------------------------------------
void whats_next() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<long long int> ar;
        read_array(ar, n);
        
        long long int tmp = 0;

        if (n % 2) {
            tmp = ar[n - 1];
            if(n == 1) {                
                ar.pop_back();
                ar.push_back(1);
                ar.push_back(1);
                ar.push_back(tmp - 1);
            } else {
                if (ar[n - 2] > 1) {
                    ar[n - 2]--;                    
                    ar.pop_back();
                    ar.push_back(1);
                    ar.push_back(1);
                    ar.push_back(tmp - 1);
                } else {
                    ar[n - 3]++;                    
                    ar.pop_back();
                    ar.pop_back();
                    ar.push_back(1);
                    ar.push_back(tmp - 1);
                }
            } 
        } else {
            tmp = ar[n - 2];
            if (n == 2) {
                
                ar[n - 2] = 1;
                ar[n - 1]++;
                ar.push_back(tmp - 1);
            } else {
                if (ar[n - 3] > 1) {
                    ar[n - 3]--;                    
                    ar[n - 2] = 1;
                    ar[n - 1]++;
                    ar.push_back(tmp - 1);
                } else {
                    ar[n - 4]++;
                    ar[n - 3] = ar[n - 1] + 1;
                    ar[n - 2]--;
                    ar.pop_back();
                }
            }
        }

        if (ar[ar.size() - 1] == 0) {
            ar.pop_back();
        }

        cout << ar.size() << endl;
        for (auto a: ar) {
            cout << a << " ";            
        }
        cout << endl;
    }
}

//-----------------------------------------------------------------------------
void cipher() {
    int n, k;
    cin >> n;
    cin >> k;

    string s;
    cin >> s;

    vector<int> cipher_ar(n);
    vector<int> orig_ar(n);

    for (int i = 0; i < n; i++) {
        cipher_ar[i] = s[i] - '0';

        if (i == 0) {
            orig_ar[0] = cipher_ar[0];
        } else {
            if (i < k )
                orig_ar[i] = cipher_ar[i] ^ cipher_ar[i - 1];
            else
                orig_ar[i] = cipher_ar[i] ^ cipher_ar[i - 1] ^ orig_ar[i - k];
        }

        cout << orig_ar[i];
    }
}

//-----------------------------------------------------------------------------
void winning_lottery_ticket() {
    int n;
    cin >> n;
    
    long long int masks_count[1024] = { 0 };

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        
        int mask = 0;

        for (int j = 0; j < tmp.size(); j++) {

            int digit = tmp[j] - '0';
            mask |= 1 << digit;
        }

        masks_count[mask]++;
    }
            
    long long int count = 0;


    for (int i = 0; i < 1023; i++) {
        if (!masks_count[i]) continue;

        for (int j = i + 1; j < 1024; j++) 
            if ((i | j) == 1023)
                count += masks_count[i] * masks_count[j];        
    }

    count += masks_count[1023] * (masks_count[1023] - 1) / 2;

    cout << count;
}

//-----------------------------------------------------------------------------
void and_product() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long int a, b;
        cin >> a >> b;
      
        long long int pw = 0;

        while (a != b) {
            a = a >> 1;
            b = b >> 1;
            pw++;
        }
       
        long long int res = a << pw;

        cout << res << endl;
    }    
}

//-----------------------------------------------------------------------------

static int left_bit(long long val) {
    int msb = 1 << 63;

    while ((msb & val) != msb) 
        msb >>= 1;

    return msb;
}

void minimax_problem() {
    int n;
    cin >> n;

    vector<int> ar;
    read_array(ar, n);

    sort(ar.begin(), ar.end());
    
    // max numer is 10 ^ 9 
    int found = -1;
    for (int pwr = 31; pwr >= 0; pwr--) {
        int mask = 1 << pwr;
        for (int i = n - 1; i >= 1; i--) {
            if ( ((ar[i] & mask) != 0) && (ar[i - 1] & mask) == 0) {
                found = i;
                break;
            }
        }

        if (found != -1)
            break;
    }

    if (found == -1) {
        cout << 0 << endl;
        return;
    }

    int min_value = 1000000000;

    for (int i = found; i < n; i++) {
        for (int j = 0; j < found; j++)
            min_value = min(min_value, ar[j] ^ ar[i]);
    }

    cout << min_value << endl;
}

//-----------------------------------------------------------------------------

void xoringNinja() {
    
    int t;

    cin >> t;

    const int div = 1000000007;


    while (t > 0) {
        int n;

        cin >> n;
        
        int  ret = 0;
        int  pw = 1;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            ret |= k;
            ret %= div;
            if (i)
                pw <<= 1;
            pw %= div;
        }

        long long int res = ret * pw;
        cout << res % div << endl;
        t--;
    }
   
}