#include <iostream>
#include <memory>
using namespace std;

class Example {
private:
    int m_v1;
    long m_v2;
public:    
    Example(int v1) : m_v1(v1) {
        cout << "int v1 ctor" << endl;
    }
    
    // Example(long v2) : m_v2(v2) {
    //     cout << "bool v2" << endl;
    // }
    
    void getV1() {
        cout << m_v1 << endl;
    }
    
    ~Example() {
        cout << "Example Destructor called" << endl;
    }
};

int main() {
  {
    unique_ptr<Example> exampleptr{new Example{13}}; 
    exampleptr->getV1();
    unique_ptr<Example> exampleptr2;
    exampleptr2 = move(exampleptr);
    exampleptr2->getV1();
        
    // SegFault
    // exampleptr->getV1();
  }
  
  {
    shared_ptr<Example> s_example_1(new Example{13});
    shared_ptr<Example> s_example_2 = s_example_1;
    
    s_example_1->getV1();
    s_example_2->getV1();
    
    cout << "Shared: " << s_example_2.use_count() << endl;
  }
}