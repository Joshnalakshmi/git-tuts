#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Control {
    int uniqueId;
    string type;
    string state;

bool operator==(const Control& other) const {
        return uniqueId == other.uniqueId;
    }
};

bool isVisible(const Control& ctrl) {
    return ctrl.state == "visible";
}

int main()
    {
        vector<Control>  
        controls ={
            {1,"slider","visible"},
            {2,"button","disabled"},
            {3,"slider","invisible"},
            {4,"button","visible"},
            {5,"button","visible"},
            {6,"slider","disabled"},
            {7,"slider","invisible"},
            {8,"slider","invisible"},
            {9,"button","disabled"},
            {10,"button","visible"}
        };
        cout << "display all controls \n"  ;
        for_each(controls.begin(),controls.end(), [] (const Control& ctrl){
            cout << "uniqueId :" << ctrl.uniqueId << "," << "type: "  << ctrl.type <<" ,"<< "state:  " << ctrl.state << endl  ; 

        });

        cout << endl;

        int targetId = 13;
        auto it = find(controls.begin(), controls.end(), Control{targetId, "", ""});
        if (it != controls.end())
        {
            cout << "Control with Id "<< targetId<< " " << "found:" <<  it-> type <<  "  " << it -> state << "\n";
        }
        else 
        { 
            cout  << "Control with Id" << " " <<  targetId << ":"  << "not found"  << "\n" ;
        }

        auto invisible = find_if(controls.begin(),controls.end(), [](const Control& ctrl){
          return ctrl.state == "invisible";
        });
        if (invisible != controls.end())
        {
        cout << " invisible Control with Id:"<< invisible -> uniqueId << ","<< "Type:"<< invisible -> type << ","<< "State:" <<  invisible-> state  << "\n";
        }
        else 
        { 
        cout  << "invisible Control with Id not found"  << "\n" ;
        }

        auto adjfind = adjacent_find(controls.begin(),controls.end(),[] (const Control& a, const Control& b){
         return a.state == b.state;
        });

        if(adjfind != controls.end()) {
            cout << "Found two consecutive controls with same state:" << endl
            << "control 1 - ID:" << " " << adjfind ->uniqueId  <<","<< "Type:" << adjfind ->  type << "," << "State:" << adjfind -> state << endl 
            << "control 2 - ID:" << " " << (adjfind+1) -> uniqueId << "," << "Type:" << (adjfind +1) ->  type  << "," << "State:" << (adjfind+1) -> state << endl;    
        }
        else
        {
            cout << "No consecutive controls with same state found \n"  << "\n" ;
        }
        int visible_count = count_if(controls.begin(), controls.end(), isVisible);

  
        cout << "Number of visible controls: " << visible_count << endl;

       

        int disabledSlidersCount = count_if(controls.begin(), controls.end(), [](const Control& ctrl) {
        return ctrl.type == "slider" && ctrl.state == "disabled";
        });
        cout << "Number of disabled sliders: " << disabledSlidersCount << endl;

        bool areEqual = equal(controls.begin(), controls.begin() + 3, controls.begin() + 3);
        cout << "\nFirst three controls are " << (areEqual ? "identical" : "not identical") << " to the next three.\n";

    }
