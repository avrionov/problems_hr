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
#include <numeric>
#include <chrono>




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
			std::vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
			cout << nums[n-1];
		}
	}
}

//-----------------------------------------------------------------------------
void for_loop() {

	std::vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

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
void update(int *a, int *b) {
	
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

	for (int i = n - 1; i >= 0; i--)
		cout << ar[i] << " ";
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
	do
	{
		ss >> i;
		integers.push_back(i);
	} while (ss >> ch);

	//while (ss >> i) //Extract integers from line
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
		void set_age(int age) {
			_age = age;
		}

		int get_age() {
			return _age;
		}

		string get_first_name() {
			return _first_name;
		};
		
		void set_first_name(const string& first_name) {
			_first_name = first_name;
		}

		string get_last_name() {
			return _last_name;
		};

		void set_last_name(const string& last_name) {
			_last_name = last_name;
		}

		void set_standard(int standard) {
			_standard = standard;
		}

		int get_standard() {
			return _standard;
		}

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
	int n; // number of students
	cin >> n;
	Student2 *s = new Student2[n]; // an array of n students

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
struct Student {
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
	Box(): _length(0), _breadth(0), _height(0) {
	};

	Box(int length, int breadth, int height) : _length(length), _breadth(breadth), _height(height) {
	};

	Box(Box& box) {
		_length = box._length;
		_breadth = box._breadth;
		_height = box._height;
	};


	// Return box's length
	const int getLength () {
		return _length;
	}

	// Return box's breadth
	const int getBreadth() {
		return _breadth;
	}

	//Return box's height
	const int getHeight() {
		return _height;
	}

	// Return the volume of the box
	long long CalculateVolume() {
		long long tmp = _length;
		tmp *= _breadth;
		tmp *= _height;
		return tmp;
	};

	//Overload operator < as specified
	bool operator<(Box& b) {
		if (_length < b._length)
			return true;

		if ((_breadth < b._breadth) && (_length == b._length))
			return true;

		if ((_height < b._height) && (_breadth == b._breadth) && (_length == b._length))
			return true;

		return false;
	};

	//Overload operator << as specified
	
  private:
	  int _length;
	  int _breadth;
	  int _height;

};

ostream& operator<<(ostream& out,  Box& b) {
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

	ar.erase(begin(ar) + pos-1);

	int p1, p2;
	cin >> p1 >> p2;

	ar.erase(begin(ar) + p1-1, begin(ar) + p2-1);

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
			case 1: s.insert(num); break;
			case 2: s.erase(num); break;
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
		virtual void display() {
			cout << _width << " " << _height << endl;
		};


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

		virtual void display() {
			cout << _width * _height << endl;
		}
};

//-----------------------------------------------------------------------------
template <class T>
class AddElements {

	T _element1, _element2;
public:
	AddElements(T element1) : _element1(element1) {

	};

	T add(T element) {
		return _element1 + element;
	}
};


void test1 () {
	double element1,element2;
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
//preporcessor test

#include <limits.h>

#define INF INT_MAX
#define io(tmp) cin >> tmp
#define toStr(str) #str
#define foreach(ar, i) for (int i = 0; i < ar.size(); i++)
#define FUNCTION(name, op) void name(int& a, int b) { if (b op a) a = b; }

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main1() {
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result = ) << ' ' << ans;
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

						if (tag_name.find(">") != string::npos)
							remove_last_ch(tag_name);

						if (current_tag == "")
							current_tag = tag_name;
						else {
							current_tag += ".";
							current_tag += tag_name;
						}
					}					
				} break;;

				case '"': {
					pos = next_lexem.find_last_of('"');
					value = next_lexem.substr(1, pos - 1);
					attrib_map[attribute] = value;
				} break;

				default:
					if (first_char != '=')
						attribute = current_tag + "~" + next_lexem;
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
struct BadLengthException : public exception {

	BadLengthException(int n) {
		_n = n;
		_str = to_string(_n);
	}
	const char * what() const throw () {		
		return _str.c_str();
	}

	int _n;
	string _str;
};


//-----------------------------------------------------------------------------
// cpp exception handling
#if 0
void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    
    cout << "returning control flow to caller" << endl;
}
#endif

//-----------------------------------------------------------------------------
// overloading ostream operator
#if 0
ostream& operator<<(ostream& out,  Person& p) {
    out << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
    return out;
}

#endif

//-----------------------------------------------------------------------------

class Message {
public:
    Message() {
       
    }
    
    Message(string& message ) {
        _message = message;
        _id = _id_count;
        _id_count++;
    }
    
    const string& get_text() {
        return _message;
    }
    
    bool operator<(const Message& m)const  {
        return _id < m._id;
    }
    
protected:
    string _message;
    int _id;
    static int _id_count;
};

int Message::_id_count = 0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(string& text) {
        return Message(text);
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};

void message_order() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}



