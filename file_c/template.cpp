#include <stdexcept>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

using namespace std;
template<typename T>

class List {
    public:
    virtual ~List() = default;
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(int index) = 0;
    virtual T& get(int index) const = 0;    
    virtual int length() const = 0 ;
    virtual void clear() = 0;
    virtual void print() const = 0;
    virtual void reverse() = 0;
    virtual List<T>* subList(int start, int end) = 0;
    virtual void printStartToEnd(int start, int end) const = 0; 
    virtual double distanceEuclidean(const List<T>* image) = 0;
};
template <typename T>
class SLList : public List<T> {
    private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };

    Node* head;
    Node* tail;
    int count;
    public:
    
    SLList<T>(){  
        head = tail = nullptr;
        count = 0;
    }
    ~SLList(){
        this->clear();
    }
    void push_back(T value) override {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
        this -> count++;
    }
    void push_front(T value) override {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        this->count++;
    }
    void insert(int index, T value) override {
        if (index < 0 || index > count) return;
        Node* newNode = new Node(value, nullptr);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = newNode;
        } 
        else if(index == count){
            tail -> next = newNode;
            tail = newNode;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }   
        this -> count++;
    }
    void remove(int index) override { 
        if (index < 0 || index >= count) return;
        Node* current = head;
        if (index == 0) {
            head = head->next;
            delete current;
            if (count == 1) {
                tail = nullptr;
            }
        } 
        else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            if (index == count - 1) {
tail = current;
            }
            delete temp;
        }  
        count--;
    }
    T& get(int index) const override { 
        if (index < 0 || index >= count) throw std::out_of_range("get(): Out of range");
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
     }
    int length() const override { 
        return count; 
    }
    void clear() override { 
        Node* temp = head;
        while (temp != nullptr) {
            head = head -> next;
            delete temp;
            temp = head;
        }
    }
    void print () const override{
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void reverse() override {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        if (head == nullptr || count == 1) return;
        else
        {
            while (current)
            {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            head = prev;
            tail = head;
            while (tail->next)
            {
                tail = tail->next;
            }
        }
    }
    List<T>* subList(int start, int end) override { 
        if (this -> count <= start)
            return nullptr;
        Node* result = new Node(nullptr, nullptr);
        Node* temp = head;
        for (int i = 0; i < start && temp; i++)
        {
            temp = temp->next;
        }
        for (int i = start; i < end && temp; i++)
        {
            result->push_back(temp->data);
            temp = temp->next;
        }
        return result;
    }
    void printStartToEnd(int start, int end) const override { 
        Node* temp = head;
        for (int i = start; i < end && i < this->count; i++)
        {
            if (i == end - 1 || i == this->count - 1) cout << temp->data << endl;
            else cout << temp->data << " ";
        }
    }
    double distanceEuclidean(const List<T>* image) override {
        double distance = 0.0;
        if (image->length() >= this->length())
        {
            for (int i = 0; i < this->length(); i++)
            {
                T value1 = this->get(i);
                T value2 = image->get(i);
                distance += pow((value1 - value2), 2);
            }
            for (int i = this->length(); i < image->length() && image->length() != this->length(); i++)
            {
                T value2 = image->get(i);
                distance += value2 * value2;
            }
        }
        else
        {
            for (int i = 0; i < image->length(); i++)
            {
                T value1 = this->get(i);
                T value2 = image->get(i);
                distance += pow((value1 - value2), 2);
            }
for (int i = image->length(); i < this->length(); i++)
            {
                T value2 = this->get(i);
                distance += value2 * value2;
            }
        }
        return sqrt(distance);
    }
};
int main(){
	SLList<int> a;
	a.push_back(2);
	a.push_back(3);
	a.print();
	a.remove(1);
	a.print();
	return 0;
}
