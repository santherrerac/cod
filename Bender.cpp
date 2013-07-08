#include <iostream>
#include <cstdio>
#include <list>
#include <map>

using namespace std;

map<string,string> axis;

void init(){

    axis["+x"] = "+x";
    axis["-x"] = "-x";
    axis["+y"] = "+y";
    axis["-y"] = "-y";
    axis["+z"] = "+z";
    axis["-z"] = "-z";
}


void bend(string decision){

    string a1,a2;
    a1 = axis["+x"],a2 = axis["-x"];

    if(decision == "+y"){

        axis["+x"] = axis["+y"];
        axis["-x"] = axis["-y"];
        axis["+y"] = a2;
        axis["-y"] = a1;
    }
    else  if(decision == "-y"){

        axis["+x"] = axis["-y"];
        axis["-x"] = axis["+y"];
        axis["+y"] = a1;
        axis["-y"] = a2;
    }
    else if(decision == "+z"){

        axis["+x"] = axis["+z"];
        axis["-x"] = axis["-z"];
        axis["+z"] = a2;
        axis["-z"] = a1;
    }
    else  if(decision == "-z"){

        axis["+x"] = axis["-z"];
        axis["-x"] = axis["+z"];
        axis["+z"] = a1;
        axis["-z"] = a2;
    }
}


int main(){

    int l;
    string decision;
    list<string>::iterator it;

    while(scanf("%d\n",&l) , l){

        init();
        list<string> decisions;
        l--;

        while(l--){

            cin>>decision;
            decisions.push_front(decision);
        }

        for(it = decisions.begin();it != decisions.end();it++){

            bend(*it);
        }

        cout<<axis["+x"]<<endl;
    }

    return 0;
}
