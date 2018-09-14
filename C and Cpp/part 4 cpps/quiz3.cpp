#include<iostream>

class Monster{

public:
 
   enum MonsterType{  
    
   Dragon,
   Goblin,
   Ogre,  
   Orc,
   Skeleton,
   Troll,
   Vampire,
   Zombie,
   MAX_MONSTER_TYPE

};

private:
   
   MonsterType m_type;
   std::string m_name;
   std::string m_roar;
   int m_hitPoints;
 
public:
  
   Monster(MonsterType type,std::string name,std::string roar,int hitPoints)
          :m_type(type),m_name(name),m_roar(roar),m_hitPoints(hitPoints){}
     std::string getTypeString() const{
		switch (m_type)
		{
		case Dragon: return "Dragon";
		case Goblin: return "Goblin";
		case Ogre: return "Ogre";
		case Orc: return "Orc";
		case Skeleton: return "Skeleton";
		case Troll: return "Troll";
		case Vampire: return "Vampire";
		case Zombie: return "Zombie";
		}
	
		return "???";
	}
   
   void print() const{
		std::cout<<m_name<<" the "<<getTypeString()<<" has "<< m_hitPoints<<" hit points and says "<<m_roar<<"\n";
	}
};


int main()
{
	Monster skele(Monster::Skeleton, "Bones", "*rattle*", 4);
	skele.print();
 
    return 0;
}










