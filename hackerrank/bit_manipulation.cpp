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

long long G(long long x) {
  long long a = x % 8;
  if (a == 0 || a == 1) return x;
  if (a == 2 || a == 3) return 2;
  if (a == 4 || a == 5) return x + 2;
  if (a == 6 || a == 7) return 0;
  return 0;
}

void xor_sequence() {
  int a = 0;
  for (int i = 1; i < 100; i++) {
    cout << (i-1) << " : " << a << " "<< get_nt_xor(i-1) << " " << G(i-1) << endl;
    a = a ^ i;

  }
 

  int t;  // number of test cases
  cin >> t;

  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;

    
    long long l_x = get_nt_xor(l - 1);
    long long r_x = get_nt_xor(r);
    long long sum = r_x ^ l_x;

    long long l_g = G(l - 1);
    long long r_g = G(r);
    long long sum_g = r_g ^ l_g;

    //int current_value = get_nt_xor(l);
    /*for (int j = l + 1; j <= r; j++) {
      int next_value = current_value ^ j;
      sum = sum ^ next_value;
      current_value = next_value;
    }*/

    cout << sum <<" "<< sum_g << endl;
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
int iterateIt(vector<int> a) {

    int rep = 0;

    // remove duplicats
    int K = 32, M = 200000;
    vector<int> cleaned;
    {
        timethis t("init");
        
        vector<uint> bitfield2(M / K, 0);

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int max_a = 0;
        int min_a = 100001;
        for (int i = 0; i < a.size(); ++i)
            for (int j = i + 1; j < a.size(); ++j) {
                int diff = a[j] - a[i];                
                bitfield2[diff / K] |= 1 << (diff % K);
                max_a = max(max_a, diff);
                min_a = min(min_a, diff);
            }

        for (int i = min_a; i <= max_a; i++)
            if ((bitfield2[i / K] >> (i % K)) & 1)    
                cleaned.push_back(i);
    }
    
    rep++;

    if (cleaned.size() == 0) return rep;
    
    {
        timethis t("gcd");
        
        int g = cleaned[0];
        for (int i  = 1; i < cleaned.size(); ++i)
            g = gcd(g, cleaned[i]);

        for (int i = 0; i < cleaned.size(); ++i)
            cleaned[i]= cleaned[i] / g;
    }

    cout << string("cleaned size: ") << cleaned.size() << endl;

    vector<uint> bitfield(M / K, 0);

    {
        timethis t("initb");        

        for (int i = 0; i < cleaned.size(); ++i) {
            for (int j = i+1; j < cleaned.size(); ++j) {
                int diff = cleaned[j] - cleaned[i];                
                bitfield[(diff - 1) / K] |= 1 << ((diff - 1) % K);
            }
        }
    }
            
    rep++;

    int max_number = cleaned[cleaned.size()-1] - cleaned[0];;

    while (max_number > 0 && (bitfield[0] & 1) == 0) {
        vector<uint> tmp_bitfield(M / K, 0);
        bool b = false;
        int m2 = max_number;
        for (int i = 0; i < max_number; i++)
            if ((bitfield[i / K] >> (i % K)) & 1) {

                if (!b) 
                    m2 = max_number - (i + 1);

                b = true;

                if (i % K < 31)
                    for (int j = i / K; j < M / K; j++)
                        tmp_bitfield[j - i / K] |= bitfield[j] >> (i % K + 1);

                for (int j = i / K + 1; j < M / K; j++)
                    tmp_bitfield[j - i / K - 1] |= (bitfield[j] << (K - 1 - i % K));
            }
        bitfield = tmp_bitfield;        
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
    vector<int> a = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
    vector<int> a_test_4 = { 17, 33, 65, 129, 257, 513, 1025, 2049, 4097, 8193, 16385, 32769 };


    int n;
    cin >> n;

    vector<int> ar;

    read_array(ar, n);

    int ret = iterateIt(ar);

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

vector<int> xorSubsequence(vector<long> a) {
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

     /*
     vector < vector<long>> DP(n + 2, vector<long>(m + 2, 0));

     DP[0][0] = -1;
     DP[1][0] = -1;
     //filling all possible xor values in the first row
     for (int i = 1; i < m + 2; i++)
     {
         DP[0][i] = i - 1;
         DP[1][i] = 0;
     }

     //filling all the array elements in the first column
     for (int i = 2; i < n + 2; i++)
     {
         DP[i][0] = a[i - 2];
     }

     DP[1][1] = 1;
     //Filling the DP table
     //according to given logic
     for (int i = 2; i < n + 2; i++)
     {
         for (int j = 1; j < m + 2; j++)
         {
             if (DP[i - 1][j] != 0)
             {
                 DP[i][((j - 1) ^ a[i - 2]) + 1] =
                     DP[i - 1][((j - 1) ^ a[i - 2]) + 1] + DP[i - 1][j];
             }
         }
         for (int j = 1; j < m + 2; j++)
         {
             DP[i][j] = max(DP[i - 1][j], DP[i][j]);
         }
     }

     for (int i = 0; i < n + 2; i++)
     {
         for (int j = 0; j < m + 2; j++)
         {
             cout << DP[i][j] << "\t";
         }
         cout << "\n";
     }

     */


    int max_count = 0;
    
    
    for (int i = 0; i < m; i++)
        if (max_count < dp[n][i]) {
            max_count = dp[n][i];
            max_num = i;
        }
    /*
    for (int i = 0; i < n; i++)
        if (a[i] == max_num)
            max_count++;
            */
    vector<int> result;

    result.push_back(max_num);
    result.push_back(max_count);

    return result;
}
