#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include <string>

#define MALE 'M'
#define FEMALE 'F'

namespace family
{
    static int generation = 0;
    static bool male =true;
    class Tree
    {
    public:
        Tree();
        Tree(std::string name_);
        Tree& addFather(std::string son,std::string father);
        Tree& addMother(std::string son,std::string father);
        void display();
        std::string relation(std::string name);
        std::string find(std::string name);
        void remove(std::string name);
        bool search(Tree* tree, std::string person, std::string parent, bool flag);
        std::string getName() const;
        bool search(Tree* tree, std::string person);
        Tree(std::string name_, char gender);


        std::string name;
        Tree *father;
        Tree *mother;
        char flag_gender;



    };
}

#endif