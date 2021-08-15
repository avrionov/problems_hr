#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <bitset>
#include <limits>  
#include <functional>


 
 
using namespace std;
using namespace std::chrono;

typedef unsigned long long int uint64;

//-----------------------------------------------------------------------------
void input_output() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << a + b + c;
}

//-----------------------------------------------------------------------------
void basic_data_types() {
  int int_v;
  long long int long_v;
  char char_v;
  float float_v;
  double double_v;

  cin >> int_v >> long_v >> char_v >> float_v >> double_v;

  cout << int_v << endl;
  cout << long_v << endl;
  cout << char_v << endl;
  cout << std::setprecision(3) << std::fixed << float_v << endl;
  cout << std::setprecision(9) << std::fixed << double_v << endl;
}

//-----------------------------------------------------------------------------
void conditional_statements() {
  int n;

  cin >> n;

  if (n > 9)
    cout << "Greater than 9";
  else {
    if (n > 0) {
      std::vector<string> nums = {"one", "two",   "three", "four", "five",
                                  "six", "seven", "eight", "nine"};
      cout << nums[n - 1];
    }
  }
}

//-----------------------------------------------------------------------------
void for_loop() {
  std::vector<string> nums = {"one", "two",   "three", "four", "five",
                              "six", "seven", "eight", "nine"};

  int a, b;
  cin >> a >> b;

  for (int i = a; i <= b; i++) {
    if (i > 0) {
      if (i > 9) {
        if (i % 2 == 0)
          cout << "even" << endl;
        else
          cout << "odd" << endl;
      } else {
        cout << nums[i - 1] << endl;
      }
    }
  }
}

int max_of_four(int a, int b, int c, int d) {
  int tmp = max(a, b);

  tmp = max(c, tmp);
  tmp = max(d, tmp);

  return tmp;
}

//-----------------------------------------------------------------------------
void functions() {
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  cout << max_of_four(a, b, c, d);
}

//-----------------------------------------------------------------------------
// pointers challange
void update(int* a, int* b) {
  int val1 = *a + *b;
  int val2 = abs(*a - *b);

  *a = val1;
  *b = val2;
}

//-----------------------------------------------------------------------------
void array_introduction() {
  int n;
  vector<int> ar;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ar.push_back(tmp);
  }

  for (int i = n - 1; i >= 0; i--) cout << ar[i] << " ";
}

//-----------------------------------------------------------------------------
void variable_size_arrays() {
  int n, q;

  cin >> n >> q;

  std::vector<std::vector<int>> ar;

  string line;

  for (int i = 0; i < n; i++) {
    vector<int> tmp_ar;

    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int tmp;
      cin >> tmp;
      tmp_ar.push_back(tmp);
    }

    ar.push_back(tmp_ar);
  }

  for (int l = 0; l < q; l++) {
    int i, j;

    cin >> i >> j;

    if (i >= 0 && i < ar.size()) {
      vector<int>& tmp_ar = ar[i];
      if (j >= 0 && j < tmp_ar.size()) {
        cout << tmp_ar[j] << endl;
      }
    }
  }
}

//-----------------------------------------------------------------------------
// string stream
vector<int> parseInts(string str) {
  vector<int> integers;

  std::stringstream ss(str);
  int i;
  char ch;
  do {
    ss >> i;
    integers.push_back(i);
  } while (ss >> ch);

  // while (ss >> i) //Extract integers from line
  //	integers.push_back(i);
  return integers;
}

//-----------------------------------------------------------------------------
void strings() {
  string a, b;

  cin >> a;
  cin >> b;

  cout << a.size() << " " << b.size() << endl;
  cout << a + b << endl;

  if (a.size() > 0 && b.size() > 0) {
    char tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
  }

  cout << a << " " << b << endl;
}

//-----------------------------------------------------------------------------
class Student1 {
 public:
  void set_age(int age) { _age = age; }

  int get_age() { return _age; }

  string get_first_name() { return _first_name; };

  void set_first_name(const string& first_name) { _first_name = first_name; }

  string get_last_name() { return _last_name; };

  void set_last_name(const string& last_name) { _last_name = last_name; }

  void set_standard(int standard) { _standard = standard; }

  int get_standard() { return _standard; }

  string to_string() {
    std::ostringstream ss;
    ss << _age << "," << _first_name << "," << _last_name << "," << _standard;
    return ss.str();
  }

 private:
  int _age;
  int _standard;

  string _first_name;
  string _last_name;
};


//-----------------------------------------------------------------------------
class Student2 {
 public:
  void input() {
    string str;

    for (int i = 0; i < 5; i++) {
      int tmp;
      cin >> tmp;
      _scores.push_back(tmp);
    }
  }

  int calculateTotalScore() {
    return accumulate(begin(_scores), end(_scores), 0);
  }

 private:
  vector<int> _scores;
};

void classes_and_objects() {
  int n;  // number of students
  cin >> n;
  Student2* s = new Student2[n];  // an array of n students

  for (int i = 0; i < n; i++) {
    s[i].input();
  }

  // calculate kristen's score
  int kristen_score = s[0].calculateTotalScore();

  // determine how many students scored higher than kristen
  int count = 0;
  for (int i = 1; i < n; i++) {
    int total = s[i].calculateTotalScore();
    if (total > kristen_score) {
      count++;
    }
  }

  // print result
  cout << count;
}

//-----------------------------------------------------------------------------
struct Student3 {
  int age;
  string first_name;
  string last_name;
  int standard;
};


//-----------------------------------------------------------------------------
void vector_sort() {
  int n;

  cin >> n;

  vector<int> ar;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ar.push_back(tmp);
  }

  sort(begin(ar), end(ar));

  for (int i = 0; i < n; i++) {
    cout << ar[i] << " ";
  }
}

//-----------------------------------------------------------------------------
class Box {
 public:
  Box() : _length(0), _breadth(0), _height(0){};

  Box(int length, int breadth, int height)
      : _length(length), _breadth(breadth), _height(height){};

  Box(Box& box) {
    _length = box._length;
    _breadth = box._breadth;
    _height = box._height;
  };

  // Return box's length
  const int getLength() { return _length; }

  // Return box's breadth
  const int getBreadth() { return _breadth; }

  // Return box's height
  const int getHeight() { return _height; }

  // Return the volume of the box
  long long CalculateVolume() {
    long long tmp = _length;
    tmp *= _breadth;
    tmp *= _height;
    return tmp;
  };

  // Overload operator < as specified
  bool operator<(Box& b) {
    if (_length < b._length) return true;

    if ((_breadth < b._breadth) && (_length == b._length)) return true;

    if ((_height < b._height) && (_breadth == b._breadth) &&
        (_length == b._length))
      return true;

    return false;
  };

  // Overload operator << as specified

 private:
  int _length;
  int _breadth;
  int _height;
};

ostream& operator<<(ostream& out, Box& b) {
  out << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();
  return out;
}

//-----------------------------------------------------------------------------
void vector_erase() {
  int n;

  cin >> n;

  vector<int> ar;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ar.push_back(tmp);
  }

  int pos;
  cin >> pos;

  ar.erase(begin(ar) + pos - 1);

  int p1, p2;
  cin >> p1 >> p2;

  ar.erase(begin(ar) + p1 - 1, begin(ar) + p2 - 1);

  cout << ar.size() << endl;
  for (int i = 0; i < ar.size(); i++) {
    cout << ar[i] << " ";
  }
}

//-----------------------------------------------------------------------------
void lower_bound() {
  int n;

  cin >> n;

  vector<int> ar;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ar.push_back(tmp);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int tmp;
    cin >> tmp;

    std::vector<int>::iterator low;
    low = lower_bound(begin(ar), end(ar), tmp);

    if (*low == tmp) {
      cout << "Yes " << low - begin(ar) + 1 << endl;
    } else {
      cout << "No " << low - begin(ar) + 1 << endl;
    }
  }
}


//-----------------------------------------------------------------------------
void sets_stl() {
  set<int> s;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int q, num;
    cin >> q >> num;

    switch (q) {
      case 1:
        s.insert(num);
        break;
      case 2:
        s.erase(num);
        break;
      case 3: {
        set<int>::iterator it = s.find(num);
        if (it == s.end())
          cout << "No" << endl;
        else
          cout << "Yes" << endl;
      } break;
    }
  }
}

//-----------------------------------------------------------------------------
void maps_stl() {
  map<string, int> mp;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int q, num;
    string name;

    cin >> q;

    switch (q) {
      case 1: {
        cin >> name;
        cin >> num;
        mp[name] += num;
        break;
      };

      case 2: {
        cin >> name;
        mp.erase(name);
        break;
      }

      case 3: {
        cin >> name;
        map<string, int>::iterator it = mp.find(name);
        if (it == mp.end())
          cout << "0" << endl;
        else
          cout << it->second << endl;
      } break;
    }
  }
}

//-----------------------------------------------------------------------------
class Rectangle {
 public:
  virtual void display() { cout << _width << " " << _height << endl; };

 protected:
  int _height;
  int _width;
};

class RectangleArea : public Rectangle {
 public:
  void read_input() {
    cin >> _width;
    cin >> _height;
  }

  virtual void display() { cout << _width * _height << endl; }
};

//-----------------------------------------------------------------------------
template <class T>
class AddElements {
  T _element1, _element2;

 public:
  AddElements(T element1)
      : _element1(element1){

        };

  T add(T element) { return _element1 + element; }
};

void test1() {
  double element1, element2;
  cin >> element1 >> element2;
  AddElements<double> myfloat(element1);
  cout << myfloat.add(element2) << endl;
}

void improveIO() {
  static bool improve = false;
  if (improve == false) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    improve = true;
  }
}

//-----------------------------------------------------------------------------
// preporcessor test

#include <limits.h>

#define INF INT_MAX
#define io(tmp) cin >> tmp
#define toStr(str) #str
#define foreach(ar, i) for (int i = 0; i < ar.size(); i++)
#define FUNCTION(name, op)   \
  void name(int& a, int b) { \
    if (b op a) a = b;       \
  }

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main1() {
  int n;
  cin >> n;
  vector<int> v(n);
  foreach (v, i) { io(v)[i]; }
  int mn = INF;
  int mx = -INF;
  foreach (v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  int ans = mx - mn;
  cout << toStr(Result =) << ' ' << ans;
  return 0;
}

//-----------------------------------------------------------------------------
void remove_last_ch(string& str) {
  // remove last character;
  str = str.substr(0, str.length() - 1);
}

void attribute_parser() {
  int n, q;

  cin >> n;
  cin >> q;

  cin.ignore();

  string current_tag;
  map<string, string> attrib_map;

  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    stringstream str_stream(line);
    string next_lexem;
    string value, attribute;

    while (getline(str_stream, next_lexem, ' ')) {
      char first_char = next_lexem[0];
      int pos;
      switch (first_char) {
        case '<': {
          string tag_name;
          // closing tag
          if (next_lexem[1] == '/') {
            tag_name = next_lexem.substr(2);
            remove_last_ch(tag_name);

            pos = current_tag.find('.');
            if (pos == string::npos)
              current_tag = "";
            else
              current_tag = current_tag.substr(0, pos);

          } else {
            tag_name = next_lexem.substr(1);

            if (tag_name.find(">") != string::npos) remove_last_ch(tag_name);

            if (current_tag == "")
              current_tag = tag_name;
            else {
              current_tag += ".";
              current_tag += tag_name;
            }
          }
        } break;
          ;

        case '"': {
          pos = next_lexem.find_last_of('"');
          value = next_lexem.substr(1, pos - 1);
          attrib_map[attribute] = value;
        } break;

        default:
          if (first_char != '=') attribute = current_tag + "~" + next_lexem;
          break;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    string line;
    getline(cin, line);
    if (attrib_map.find(line) == attrib_map.end())
      cout << "Not Found!" << endl;
    else
      cout << attrib_map[line] << endl;
  }
}


//-----------------------------------------------------------------------------
class Person {
 public:
	 virtual void getdata() {
	 };

	 virtual void putdata() {
	 };

 protected:
  string _name;
  int _age;
  int _my_id;
};
	  
class Professor : public Person {
 
public:
	Professor() { 
		_curr_id_professor++;
		_my_id = _curr_id_professor;
	}

  virtual void getdata() {
	  cin >> _name;
	  cin >> _age;
	  cin >> _publications;
  };

  virtual void putdata() {
	   cout << _name << " ";
	   cout << _age << " ";
	   cout << _publications << " ";
	   cout << _my_id << endl;

  }

 protected:
  int _publications;
  static int _curr_id_professor;
};

int Professor::_curr_id_professor = 0;


class Student : public Person {

    public:

	Student () { 
	  _curr_id_student++; 
	  _my_id = _curr_id_student;
	}


	
	virtual void getdata() { 
	  cin >> _name;
	  cin >> _age;
	  for (int i = 0; i < 6; i++)
		  cin >> _marks[i];
  };

  virtual void putdata() {
	  cout << _name << " ";
	  cout << _age << " ";
	  int sum = 0;
	  for (int i = 0; i < 6; i++)
		  sum += _marks[i];

	  cout << sum << " ";
	  cout << _my_id << endl;
  }

  protected:
	int _marks[6];
    static int _curr_id_student;
};

int Student::_curr_id_student = 0;

int virtual_function_main() {
  int n, val;
  cin >> n;  // The number of objects that is going to be created.
  Person* per[10000];

  for (int i = 0; i < n; i++) {
    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student;  // Else the current object is of type Student

    per[i]->getdata();  // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata();  // Print the required output for each object.

  return 0;
}

//-----------------------------------------------------------------------------
class Matrix {
	public: 
		vector<vector<int> > a;
		Matrix operator + (Matrix& b) {
			Matrix result;
			for (int i = 0; i < a.size(); i++) {
				vector<int> res_vector;
				for (int j = 0; j < a[i].size(); j++) {
					int sum = a[i][j] + b.a[i][j];
					res_vector.push_back(sum);
				}
				result.a.push_back(res_vector);
			}

			return result;
		}
};

int matrix_main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}


//-----------------------------------------------------------------------------
struct Workshop {
	int _start_time;
	int _end_time;
	int _duraction;

	bool operator<( Workshop& b) const {
		return _end_time < b._end_time;
	}
    
    bool operator()(Workshop a, Workshop b) const
    {
        return a._end_time < b._end_time;;
    }
};





struct Available_Workshops {
	int _n;
	std::vector<Workshop> _workshops;

	
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
	Available_Workshops* ptr = new Available_Workshops();

	ptr->_n = n;

	for (int i = 0; i < n; i++) {
		Workshop w;
		w._start_time = start_time[i];
		w._duraction = duration[i];
		w._end_time = start_time[i] + duration[i];

		ptr->_workshops.push_back(w);
	}

	return ptr;
}


// Greedy algorithm- Select the interval which ends first (but still not overlappingthe already chosen intervals)
int CalculateMaxWorkshops(Available_Workshops* ptr) {
	
	int n = ptr->_n;

	// handle the corner case
	if (n <= 1) return n;
	
    // TODO fix this
    // does not compile on mac os because compare operator
	//std::sort(begin(ptr->_workshops), end(ptr->_workshops));

	std::vector<Workshop> non_overlap;
	Workshop last_int = ptr->_workshops[0];
	non_overlap.push_back(last_int);

	// important >= for overlaping time
	for (int i = 1; i < n; i++) {
		if (ptr->_workshops[i]._start_time >= last_int._end_time) {
			last_int = ptr->_workshops[i];
			non_overlap.push_back(last_int);
		}
	}

	return non_overlap.size();
}

int attending_workshops_main() {
	int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;

}

//-----------------------------------------------------------------------------
void printKMax(int arr[], int n, int k) 
{     
    std::deque<int>  inter_deque(k); 

	int i;
    for (i = 0; i < k; ++i)  { 
        
        while ( (!inter_deque.empty()) && arr[i] >= arr[inter_deque.back()]) 
            inter_deque.pop_back();  
          
        inter_deque.push_back(i); 
    } 
      
    for ( ; i < n; ++i)  { 
    
        cout << arr[inter_deque.front()] << " "; 
      
        while ( (!inter_deque.empty()) && inter_deque.front() <= i - k) 
            inter_deque.pop_front();  
  
        while ( (!inter_deque.empty()) && arr[i] >= arr[inter_deque.back()]) 
            inter_deque.pop_back(); 
      
        inter_deque.push_back(i); 
    }   
    
    cout << arr[inter_deque.front()];  

	cout << endl;
} 

int deque_main () {
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[100];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

//-----------------------------------------------------------------------------
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;

   Node(Node* p, Node* n, int k, int val)
	   :prev(p), next(n), key(k), value(val) {
   };
   Node(int k, int val)
	   :prev(NULL), next(NULL),key(k),value(val) {
   };
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

// "least recently used" (LRU).
// both put and get move an item to the head - count as use
class LRUCache  {
	
public:

	LRUCache(int capcity) {
		_capacity = capcity;
	};

	int get(int key) {
		auto it = _storage.find(key);
		if (it == _storage.end()) {
			return -1;
		} else {
			// move to the top of the cache
			int value = *it->second;
			_cache_list.erase(it->second);
			_cache_list.push_front(value);
			_storage[key] = _cache_list.begin();
			return value;
		}
	}

	void set(int key, int value) {
		auto it = _storage.find(key);
		if (it == _storage.end()) {
			_cache_list.push_front(value);
			_storage[key] = _cache_list.begin();

			// check if the cache is too big
			if (_cache_list.size() > _capacity) {
				auto last = _cache_list.end();
				last--;

				_cache_list.pop_back();
				//_storage.erase(last);

				for (auto it = _storage.begin(); it != _storage.end(); ++it){
				   if (it->second == last)  { 
					   _storage.erase(it); 
					   break; 
					}
}
			}

		} else {			
			_cache_list.erase(it->second);
			_cache_list.push_front(value);
			_storage[key] = _cache_list.begin();
		}
		
	}

private:
	std::list<int> _cache_list;
	std::unordered_map<int, list<int>::iterator> _storage;
	
	int _capacity;
};


int polymorphism_main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


//-----------------------------------------------------------------------------

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 

string SpellJournal::journal = "";

//-----------------------------------------------------------------------------
void counterspell(Spell *spell) {
	Fireball *fireball = dynamic_cast<Fireball*>(spell);
    Frostbite *frostbite = dynamic_cast<Frostbite*>(spell);
    Waterbolt *waterbolt= dynamic_cast<Waterbolt*>(spell);
    Thunderstorm *thunderstorm = dynamic_cast<Thunderstorm*>(spell);

	if (fireball != NULL) {
		fireball->revealFirepower();
	}
	else if (frostbite != NULL) {
		frostbite->revealFrostpower();
	} else if (thunderstorm != NULL) {
		thunderstorm->revealThunderpower();
	}
	else if (waterbolt != NULL) {
		waterbolt->revealWaterpower();
	}
	else {
		 string x = spell->revealScrollName();
		 string y = SpellJournal::read();
		 const int arSize = 5000;
			auto m = x.length();
			auto n = y.length();

			//int *l = new int [m + 1][n + 1];
			auto l = new int[arSize + 1][arSize + 1];
			size_t i, j;
        
			for (i = 0; i <= m; i++) {
				for (j = 0; j <= n; j++) {

					if (i == 0 || j == 0)
						l[i][j] = 0;

					else if (x[i - 1] == y[j - 1])
						l[i][j] = l[i - 1][j - 1] + 1;
					else
						l[i][j] = max(l[i - 1][j], l[i][j - 1]);
				}
			
			}    
			int ret = l[m][n];    
			
			cout << ret << endl; 
	}
}


class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int wizard_main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}


//-----------------------------------------------------------------------------
template <bool... digits> int reversed_binary_value() {
    bool binary[] = { digits... };
	int sum = 0;  
	int mult = 1;

	for (auto digit : binary) {
		sum += (digit ? mult : 0);
		mult *= 2;
	}

	return sum;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int variadics_main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}

	return 0;
}

//-----------------------------------------------------------------------------

class fast_bit_array {

public:
	fast_bit_array(unsigned int size) {
		_a = new unsigned int[size / 32];
		memset(_a, 0, sizeof(int) * (size / 32));
	}

	~fast_bit_array() {
		delete[] _a;
	}

	inline void set(unsigned int k) {
		_a[(k / 32)] |= (1 << (k % 32));
	}

	unsigned int inline test(unsigned k) {
		return  _a[(k / 32)] & (1 << (k % 32));
	}

	unsigned int* _a;
};

const unsigned int max_int = 1 << 31;

unsigned int bit_func(unsigned int a, unsigned int p, unsigned int q) {
	return  (a *p + q) % max_int;
}


//typedef unsigned int (*bit_func_t)(unsigned int);

typedef std::function<unsigned int (unsigned int)> bit_func_t;

int brent(unsigned int n, unsigned int s, bit_func_t bit_func) {
    	
	unsigned long long tortoise, hare, count = 0;
    
	unsigned long long x0  = s % max_int;

	tortoise = bit_func(x0);
    hare = bit_func(x0);
	hare = bit_func(hare);

	while (tortoise != hare) {
        if (count >= n) {
			return count;
        } else {
            count++;
        }
        tortoise = bit_func(tortoise);
        hare = bit_func(hare) ;
        hare = bit_func(hare);
    }

    unsigned long long mu = 0;
    tortoise = x0;
    while (tortoise != hare) {
        tortoise = bit_func(tortoise);
        hare = bit_func(hare);
        mu++;
    }

    unsigned long long lam = 1;
    hare = bit_func(tortoise);
    while (tortoise != hare) {
        hare = bit_func(hare);
        lam++;
    }
    
	return lam + mu;    
}

int brent2(unsigned int n, unsigned int s,  unsigned int p, unsigned int q) {
    	
	unsigned long long tortoise, hare, count = 0;
    
	unsigned long long x0  = s % max_int;

	tortoise = bit_func(x0, p, q);
    hare = bit_func(x0, p, q);
	hare = bit_func(hare, p, q);

	while (tortoise != hare) {
        if (count >= n) {
			return count;
        } else {
            count++;
        }
        tortoise = bit_func(tortoise, p, q);
        hare = bit_func(hare, p, q) ;
        hare = bit_func(hare, p, q);
    }

    unsigned long long mu = 0;
    tortoise = x0;
    while (tortoise != hare) {
        tortoise = bit_func(tortoise, p, q);
        hare = bit_func(hare, p, q);
        mu++;
    }

    unsigned long long lam = 1;
    hare = bit_func(tortoise, p, q);
    while (tortoise != hare) {
        hare = bit_func(hare, p, q);
        lam++;
    }
    
	return lam + mu;    
}

void bit_array(unsigned int n, unsigned int s, unsigned int p, unsigned int q) {
	
	
	fast_bit_array fb(max_int);

	int count = 1;

	unsigned int a  = s % max_int;
	auto f = bind(&bit_func, std::placeholders::_1, p, q);

	cout << brent(n, s, f) << endl;
	//cout << brent2(n, s, p, q) << endl;

	return;

}

void bit_array_start() {
	unsigned int n = 100000000, s =923092883,  p =976061291, q =1205350525;
	bit_array (n, s, p, q);   
}


