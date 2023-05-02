#include <iostream>
#include <map>
#include <string>
using namespace std;
class Context {
private:
    int id;
    string variable;
public:
    Context(int i, string y) {
       id = i;
       variable = std::move(y);
    }
    bool operator<(const Context& b) const {
        if(this->id == b.id) {
            return this->variable < b.variable;
        } else {
            return this->id < b.id;
        }
    }

    friend ostream& operator<<(ostream& strm, const Context& m){
        strm << " ID: " << m.id << " and variable " << m.variable;
        return strm;
    }
};

int main(){
    map<Context, string> Contexts;
    Contexts.insert(pair<Context, string>(Context(1, "name1"), "something1"));
    Contexts.insert(pair<Context, string>(Context(2, "name2"), "something2"));
    Contexts.insert(pair<Context, string>(Context(3, "name3"), "something3"));
    cout << " Contexts: " << endl;

    for(auto const &pair : Contexts) {
        cout << "  " << pair.first << "  " << pair.second << endl;
    }

    Context idToSearch(1, "name1");
    if (Contexts.find(idToSearch) == Contexts.end()) {
        cout << "not found" << idToSearch << endl;
    } else {
        cout << " Context" << idToSearch << " belongs to " << Contexts.at(idToSearch) << endl;
    }

}