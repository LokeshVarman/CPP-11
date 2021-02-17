#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
 class Movie{
    protected:
    vector<int> movieid ={ 1, 2, 3, 4 };
    vector<string> mvname={"Master","Sivaji","Remo","Ae dil hai mushkil"};
    vector<int> rating={5,4,3,5};
    vector<int> rent={100,50,30,100};
};
class recorder:public Movie{
    int ch,mid,rat,re;string mv,findm;
    public: void one(){
        cout<<"enter movie id to be added"<<endl;
        cin>>mid;
        movieid.push_back(mid);
        cout<<"enter movie name to be added"<<endl;
        cin>>mv;
        mvname.push_back(mv);
        cout<<"enter rating of the movie"<<endl;
        cin>>rat;
        rating.push_back(rat);
        cout<<"enter rent for the movie"<<endl;
        cin>>re;
        rent.push_back(re);
        cout<<"Movie has been successfully added to the store"<<endl;
    }
    public: void two(){
        for (int i=0;i<movieid.size();i++) { 
            cout << movieid[i]<<" | "<<mvname[i]<<" | "<<rating[i]<<" | "<<rent[i]<<endl;
        } 
    }
    public: void three(){
        cout<<"Enter the movie name to search :"<<endl;
        cin>>findm;
        auto result1 = std::find(std::begin(mvname), std::end(mvname), findm);
        if (result1 != std::end(mvname)) 
            std::cout << "Movie is available "  << '\n';
        else 
            std::cout << "Movie is not available " << '\n';
    }
   
    
    
};
int main(){
    int ch,mid,rat,re;string mv,findm;
    recorder r;
    
    do{
        cout<<"1. Add a movie in store"<<endl;
        cout<<"2. Display list of movies with rating and rent"<<endl;
        cout<<"3. Search movie by name"<<endl;
        cout<<"Enter the choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                r.one();
                break;
            case 2:
                r.two();
                break;
            case 3:
                r.three();
                break;
            case 0:
                exit(0);
            default:
                cout<<"enter valid choice"<<endl;
                
        }
        
    }while(ch!=0) ;
}


