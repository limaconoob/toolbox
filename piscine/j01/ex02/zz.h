
#ifndef ZOMBIE_HPP
  #define ZOMBIE_HPP

  #include <string>
  #include <time.h>

  class Zombie
  { public:
      std::string nom;
      std::string type;

      void announce()
      { std::cout << "<" + nom + " (" + type + ")> Braiiiiiiinnnssss..." << std::endl; }};

  class Zombie_Event : public Zombie
  { public:
      void setZombieType(std::string new_type)
      { type = new_type; }

      Zombie *newZombie(std::string name)
      { Zombie *coucou = new Zombie();
        coucou.nom = name;
        coucou.type = std::string("bonjour");
        return (coucou); }

      Zombie *randomChump()
      { Zombie *coucou = new Zombie();
        time_t the_time = time(NULL);
        if (the_time % 2 == 0)
        { coucou.nom = std::string("connard"); }
        else
        { coucou.nom = std::string("connard"); }
        coucou.type = std::string("aleatoire");
        return (coucou); }};

#endif
