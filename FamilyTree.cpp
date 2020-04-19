#include <iostream>
#include <string>
#include "FamilyTree.hpp"
using namespace family;
using namespace std;

family::Tree::Tree(std::string name_)
{
    name = name_;
    father = NULL;
    mother = NULL;
    flag_gender = 'm';

}
family::Tree::Tree(std::string name_, char gender)
{
    name = name_;
    father = NULL;
    mother = NULL;
    flag_gender = gender;
}

string family::Tree::getName() const
{
    return this->name;
}

bool family::Tree::search(Tree* tree, std::string person, std::string parent, bool flag)
{

    Tree* current = tree;

    if (current == NULL)
        return false;
    else if (current->name.compare(person)==0)
    {
       if (flag)
       {
           if (current->father==NULL)
                current->father = new Tree(parent,MALE);
            else
               throw std::exception();
       }
       else
           {
               if (current->mother==NULL)
                    current->mother = new Tree(parent,FEMALE);
               else
                   throw std::exception();
           }

        return true;
    }


    if(search(current->father, person, parent,flag))
        return true;
    if (search(current->mother, person, parent,flag))
        return true;

     return false;
}

Tree& family::Tree::addFather(std::string son,std::string father) {
    if (search(this, son,father, true))
        return *this;
    else
        throw std::exception();

}

Tree& family::Tree::addMother(std::string son,std::string mother)
{
    if (search(this, son,mother, false))
        return *this;
    else
        throw std::exception();
}

void family::Tree::display()
{
    return;
}

bool family::Tree::search(Tree* tree, std::string person)
{

    Tree* current = tree;

    if (current == NULL)
        return false;
    else if(current->getName().compare(person)==0&&(generation==0))
        return true;
    else if(current->getName().compare(person)==0)
    {
        current->flag_gender == 'M' ? male = true : male = false;
        return true;
    }

    generation++;

    if(search(current->father, person))
        return true;

    if (search(current->mother, person))
        return true;
    else
        generation--;
    return false;

}

std::string family::Tree::relation(std::string name)
{
    generation = 0;
    string str="";

    if (search(this,name))
    {

        switch (generation)
        {
            case 0 :
                return "me";
            case 1 :
                if (male)
                    return "father";
                else
                    return "mother";
            case 2 :
                if (male)
                    return "grandfather";
                else
                    return "grandmother";
            default :
                for (int i = 2 ; i < generation ; i++ )
                    {
                        str += "great-";
                    }

                    if (male)
                        return str+="grandfather";
                    else
                        return str+="grandmother";
        }
    }
    else
        return "unrelated";

}
std::string family::Tree::find(std::string name)
{
    return "found";
}
void family::Tree::remove(std::string name)
{
    return;
}

/*int main()
{
    family::Tree T ("Yosef");
    T.addFather("Yosef", "Yaakov")
            .addMother("Yosef", "Rachel")
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah")
            .addMother("Terah", "b")
            .addFather("Terah","Shnuzel")
            .addMother("Rivka", "Yael")
    .addMother("Yael", "Naama");
    cout << T.relation("Isaac") << endl;
    cout << "Yael: "<< T.relation("Yael") << endl;
    cout << "Naama: "<< T.relation("Naama") << endl;
    cout << "Terah: "<< T.relation("Terah") << endl;
    cout << "Shnuzel: "<< T.relation("Shnuzel") << endl;
    cout << "Yaakov: "<< T.relation("Yaakov") << endl;
    cout << "Rachel: "<< T.relation("Rachel") << endl;
    cout << "Naama: "<< T.relation("Ziv") << endl;
    return 0;
}
 */