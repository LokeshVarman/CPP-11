#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;

class clsMovie
{
    public:
        clsMovie(int intMovieID,string strMovieName,double dblRating,int intRent);
        ~clsMovie() { cout << "destructor called" << endl;}
        string getMovieName() const;
        double getRating() const;
        int getRent() const;
    private:
        int m_intMovieID;
        string m_strMovieName;
        double m_dblRating;
        int m_intRent;
};
clsMovie::clsMovie(int intMovieID,string strMovieName,double dblRating,int intRent) :
m_intMovieID(intMovieID) , m_strMovieName(strMovieName) , m_dblRating(dblRating) , m_intRent(intRent)
{

}
string clsMovie::getMovieName() const
{
    return m_strMovieName;
}
double clsMovie::getRating() const
{
    return m_dblRating;
}
int clsMovie::getRent() const
{
    return m_intRent;
}





class clsStore
{
     public:
        void AddMovie(shared_ptr<clsMovie>);
        void displayMovies();
        void searchMovie(string strMovieName);
    private:
        unordered_map<string,shared_ptr<clsMovie>> um_Movies;
};
void clsStore::AddMovie(shared_ptr<clsMovie> pobj)
{
    um_Movies.insert(make_pair(pobj->getMovieName(), pobj));
}
void clsStore::displayMovies()
{
    cout << "***************** Current available : *****************" << endl;
    for(auto itr = um_Movies.begin();itr!=um_Movies.end();++itr)
    {
        shared_ptr<clsMovie> pobj = itr->second;
  
        string strMovieName = pobj->getMovieName();
        double dblRating = pobj->getRating();
        int intRent = pobj->getRent();

        cout << strMovieName << "-----" << dblRating << "-----" << intRent << endl;
    }
    cout << endl << "******************************************************" << endl;
}
void clsStore::searchMovie(string strMovieName)
{
    auto itr = um_Movies.find(strMovieName);
    if(itr!=um_Movies.end())
    {
        shared_ptr<clsMovie> pobj = itr->second;
  
        string strMovieName = pobj->getMovieName();
        double dblRating = pobj->getRating();
        int intRent = pobj->getRent();

        cout << strMovieName << "-----" << dblRating << "-----" << intRent << endl;
    }
    else
    {
        cout << "Movie " << strMovieName << " is not available...!" << endl;
    }
}






int main()
{
    clsStore obj_Store;
    
    obj_Store.AddMovie(make_shared<clsMovie>(1000,"A",8.9,300));
    obj_Store.AddMovie(make_shared<clsMovie>(2000,"B",7.9,250));
    obj_Store.AddMovie(make_shared<clsMovie>(3000,"C",9.4,350));

    obj_Store.displayMovies();

    obj_Store.searchMovie("D");
    cout << endl << "******************************************************" << endl;
    obj_Store.searchMovie("C");
    cout << endl << "******************************************************" << endl;
    

    cout << endl << endl << endl << endl << endl;
    cout << "***************** Programme dump : *****************" << endl;
        
    return 0;
}