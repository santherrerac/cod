//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3960

#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;

vector< string > movies;


int main() {

    string clip;

    int m,q;

    scanf("%d%d\n",&m,&q);

    while(m--){

        string temp;
        cin>>temp;
        movies.push_back(temp);
    }

    while(q--){

        cin>>clip;

        int mayor = -1;
        int im = 0;

        for(int i = 0;i<movies.size();i++ ){

            if(movies[i].size() < clip.size())continue;

            int mayorc = -1;

            for(int j = 0;j + clip.size()-1  < movies[i].size();j++ ){

                int c=0;

                for(int k = 0;k < clip.size();k++ ){

                    if(clip[k] == movies[i][j+k]) c++;
                }

                if(c >= mayorc) mayorc =c;
            }

            if(mayorc > mayor){ mayor = mayorc;  im = i; }
        }

        printf("%d\n",im+1);
    }

    return 0;
}
