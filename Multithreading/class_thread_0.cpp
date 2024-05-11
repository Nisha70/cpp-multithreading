// MULTITHREADING
#include <iostream>
#include <thread>
using namespace std;
class dotask
{
public:
    void run(const char *s, int n)
    {
        cout << s << " " << n << endl;
        
    }
};
int main()
{
    dotask dk1;
    thread t(&dotask::run, &dk1, "hi i am parallel thread", 44);
    cout << "hi i am main thread" << endl;

    t.join();
    return 0;
}
