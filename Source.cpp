#include<iostream>
#include<string>
#include<fstream>

using namespace std;

template <class T>
class Lists;

template <class T>
class Node {
	T data;
	Node * next;
public:
	Node() {
		next = nullptr;
	}
	//Parameterized Constructor
	Node(T d, Node * n) {
		data = d;
		next = n;
	}
	//Copy constructor
	Node <T>(Node <T>  & obj) {
		data = obj.data;
		next = obj.next;
		return *this;
	}
	//Destructor
	~Node() {
		//delete next;
	}
	friend class Lists <T>;
};

template <class T>
class Lists {
	Node <T> * head;
	Node <T> * tail;
	
public:
	//Iterator CLass
	class iterator {
		Node <T> * current;
	public:
		//Constructor
		iterator(Node <T> * p = nullptr) {
			current = p;
		}
		// * operator overloading
		T & operator *() {
			return current->data;
		}
		// == operator overloading
		bool operator ==(iterator itr) {
			return current == itr.current;
		}
		// != operator overloading
		bool operator !=(iterator itr) {
			return !(current == itr.current);
		}
		// ++ Pre operator overloading
		iterator operator ++() {
			current = current->next;
			return *this;
		}
		// ++ Post operator overloading
		iterator operator ++(int dummy) {
			iterator temp = *this;
			current = current->next;
			return temp;
		}
		friend class Lists<T>;
	};
	//List Constructor
	Lists() {
		head = tail = nullptr;
	}
	//List Parameterized Constructor
	Lists(int s, Node<T>* h, Node <T> * t) {
		size = s;
		head = h;
		tail = t;
	}
	//Copy Constructor
	Lists(const Lists <T>  & obj) {
		head = obj.head;
		tail = obj.tail;
	}
	//Function to insert at start of linked List
	void insertatstart(T d) {
		Node <T> * temp = new Node <T>;
		temp->data = d;
		temp->next = head;
		if (head == nullptr) {
			tail = temp;
			tail->next = nullptr;
		}
		head = temp;
	}
	// return head of the List
	iterator begin() {
		iterator itr(head);
		return itr;
	}
	//returns tail's next of the List 
	iterator end() {
		iterator itr(tail->next);
		return itr;
	}
	//Function to insert at end of linked List
	void insertatend(T d) {
		Node <T> *temp = new Node <T>;
		temp->data = d;
		temp->next = nullptr;
		tail->next = new Node <T>;
		tail->next = temp;
		if (!tail)
			head = temp;
		tail = temp;
	}
	//Function to delete at start of linked List
	void removeatstart() {
		if (head) {
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node <T> *temp = head->next;
				delete head;
				head = temp;
			}
		}
	}
	//Function to insert at end of linked List
	void removeatend() {
		if (head) {
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node <T> *temp = head->next;
				while (temp->next != tail) {
					temp = temp->next;
					temp->next = nullptr;
					delete tail;
					tail = temp;
				}
			}
		}
	}
	//Destructor
	~Lists() {
		if (head == tail) {
			delete head;
		}
		else {
			delete head;
			delete tail;
		}
	}
};

template <typename T>
class  Stack {
	Lists <T> L;
public:
	//Constructor
	Stack() {
		
	}
	//Parameterized constructor
	Stack(Lists <T> tempL) {
		L = tempL;
	}
	//checks whether stack is full
	bool isFull() {
		return false;
	}
	//checks whether stack is empty
	bool isEmpty() {
		Lists <int> ::iterator itr;
		itr = L.begin();
		if(itr==nullptr)
		return true;
		return false;
	}
	//inserts element at the top of the stack
	bool Push(const T & d) {
		if (isFull()==false) {
			L.insertatstart(d);
			return true;
		}
		else {
			cout << "Stack  is aleady Full!!" << endl;
			return false;
		}
	}
	//removes the elememt at top of the stack
	bool Pop(int & a) {
		if (!isEmpty()) {
			Lists <int> ::iterator itr;
			itr = L.begin();
			a = *itr;
			L.removeatstart();
			return true;
		}
		else {
			cout << "Array is Empty!!" << endl;
			return false;
		}
	}
	//gives the element at the top of the stack
	bool Top(T & a) {
		if (!isEmpty()) {
			Lists <int> ::iterator itr;
			itr = L.begin();
			a = *itr;
			return true;
		}
		else {
			cout << "Array is Empty!!" << endl;
			return false;
		}
	}
	//Destructor
	~Stack() {
		L.~Lists();
	}
};

class InfluenceNetwork {
	Lists <int> * Network;
public:
	//Copy Constructor
	InfluenceNetwork(InfluenceNetwork & obj) {
		Network = obj.Network;
	}
	//Constructor
	InfluenceNetwork() {
		Network = nullptr;
	}
	//Parameterized Constructor
	InfluenceNetwork(Lists <int> * Net) {
		Network = Net;
	}
	int n = 0;
	//Function to Read the network from the Txt File
	InfluenceNetwork(string filename) {
		ifstream fin(filename);
		if (fin.fail()) {
			cout << "File not open" << endl;
		}
		else {

			char line[1000];
			fin >> n;
			fin.getline(line, 200);
			Network = new Lists <int>[n];
			int m = 0;
			while (fin.getline(line, 1000))
			{
				int a = line[0]-48;
				Network[m].insertatstart(a);
				int i = 0;
				char temp[100];
				int k = 0;
				for (; (line[i] != '\0') && (line[i] != ' '); i++);
				while (line[i] != '\0')
				{
					if (line[i] == ' ')
					{
						temp[k] = '\0';
						if (temp[0] != '\0') {
						if(atoi(temp)!=0)
							Network[m].insertatend(atoi(temp));
						}
						k = 0;
					}
					else
					{
						temp[k++] = line[i];
						if (line[i + 1] == '\0')
						{
							temp[k] = '\0';
							if (temp[0] != '\0') {
							      if(atoi(temp)!=0)
								Network[m].insertatend(atoi(temp));
							}
						}
					}
					i++;
				}
				m++;
			}
			/*int i = 0; int k = 0; int m = 0; int o = 0;
			char a; int l = 0; int w = 0; int q = 0;
			fin.getline(line, 200);
			while (fin.getline(line, 200)) {
				//cout << line<<endl;
				while (line[m] != '\0' &&  m < strlen(line)) {
					a = line[m];
					if (o == 0) {
						w = a - 48;
						if (line[m] != ' ') {
							Network[i].insertatstart(w);
						}
						o++;
						m += 4;
						k++;
					}
					else {
						a = line[m];
						q = a - 48;
						if (line[m] != ' ') {
							Network[i].insertatend(q);
						}
						m += 3;
						k++;
					}
				}

				i++;
				m = 0;
				k = 0;
				o = 0;
			}*/
		}
		//Printing the content of File
		for (int i = 0; i < n; i++) {
			Lists <int> ::iterator itr;
			for (itr = Network[i].begin(); itr != Network[i].end(); itr++) {
				cout << *itr << " ";
			}
			cout << endl;
		}
	}
	//function to insert in array to be used to keep the track of the ids already checked
	void insert(int arr[], int m, int i) {
		arr[i - 1] = m;
	}
	//function to check in array to be used to keep the track of the ids already checked
	bool check(int arr[], int m,int i) {
		if (arr[i - 1] == m)
			return true;
		return false;
	}
	//function to insert id in array to be used to keep the track of the ids already checked
	void insertid(int arr[], int i) {
		arr[i - 1] = i;
	}
	//function to check in array to be used to keep the track of the ids already checked
	bool checkid(int arr[], int a, int m) {
		for (int i = 0; i < a; i++) {
			if (arr[i] == m)
				return true;
		}
		return false;
	}
	//Function to Calculate the Influence of the One Person
	int mostinfluence(int user,int n) {
		Stack <int> stack;
		int *arr = new int[n];
		int *arrid = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
			arrid[i] = 0;
		}
		int count = 0;
		Lists <int> ::iterator itr;
			for (itr = Network[user-1].begin(); itr != Network[user-1].end(); ++itr) {
				int q = *itr;
				insert(arr, 1, q);
		}
			for (int i = 1; i <= n; i++) {
				//cout << i;
				if (check(arr, 1, i) == true) {
					if (i!=user) {
						if (checkid(arrid, n, i) == false) {
							//Pushing the influnenced id on stack
							stack.Push(i);
							count++;
						}
						//Keeping track of ids already checked
						insertid(arrid, i);
						insert(arr, 1, i);
					}
					for (itr = Network[i-1].begin(); itr != Network[i-1].end(); ++itr) {
						if (checkid(arrid, n, *itr) == false && *itr!=user) {
							insertid(arrid, *itr);
						//	cout << *itr << "p";
							count++;
							//Pushing the influnenced id on stack
							stack.Push(*itr);
							//Keeping track of ids to be checked
							insert(arr, 1, *itr);
						}
					}
					//Keeping track of ids already checked
					insert(arr, -1, i);
				}
			}
			int st = 0;
			//Printing the number of influences and their ids
			cout << endl << user << " influence " << count << " persons: " << endl;
			while (stack.isEmpty() != true) {
				stack.Pop(st);
				cout << st << " ";
			}
			cout << endl;
			return count;
	}
	//Function to find the maximum influencer
	int maximum(int arr[], int n) {
		int i;
		int index = 0;
		int max = arr[0];
		bool flag = false;
		for (i = 1; i < n; i++) {
			if (arr[i] > max){
				flag = true;
				max = arr[i];
			    index = i+1;
			}
		}
		if (flag == false) {
			index += 1;
		}
		return index;
	}
	//Function to calculate the Influences of each Person in the Network and Also tells the Maximum Influencer.
	void Calculate_Influence(){
		int * arr = new int[n];
		for (int i = 1; i <= n; i++) {
			int a = mostinfluence(i, n);
			insert(arr, a, i);
		}
		cout << "Person who influences the Maximum number of individuals: " << maximum(arr, n) << endl;
   }
	//Destructor
	~InfluenceNetwork() {
			delete [] Network;
	}
};

int main() {
	string filename = "F:\\input.txt";
	InfluenceNetwork N(filename);
	N.Calculate_Influence();

	return 0;
}