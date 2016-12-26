/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:29:29 by jpepin            #+#    #+#             */
/*   Updated: 2016/12/26 12:40:33 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REP_H
#define REP_H
  #include <string>

  template <class T>
  class Repertoire
  { private:
      static int count;
      static bool flag_s;
      static bool flag_a;
      std::string names[8][11];

    public:
      void Add()
      { if (count == 88)
        { std::cout << "Le répertoire ne peut pas avoir plus de 8 noms." << std::endl;
          return; }
        flag_s = false; }

      void Next(std::string bonjour)
      { names[count / 11][count % 11] = bonjour;
        count++;
        flag_s = true; }

      void Display(void)
      { int i = 0;
        while (i < 8)
        { std::cout << std::setw(9) << i << "|";
          if (!(names[i][0].empty()) && names[i][0].size() <= 10)
          { std::cout << std::setw(10) << names[i][0]; }
          else if (names[i][0].size() > 10)
          { std::cout << names[i][0].substr(0, 9) << "."; }
          else
          { std::cout << "Inexistant"; }
          std::cout << "|";
          if (!(names[i][1].empty()) && names[i][1].size() <= 10)
          { std::cout << std::setw(10) << names[i][1]; }
          else if (names[i][1].size() > 10)
          { std::cout << names[i][1].substr(0, 9) << "."; }
          else
          { std::cout << "Inexistant"; }
          std::cout << "|";
          if (!(names[i][2].empty()) && names[i][2].size() <= 10)
          { std::cout << std::setw(10) << names[i][2]; }
          else if (names[i][2].size() > 10)
          { std::cout << names[i][2].substr(0, 9) << "."; }
          else
          { std::cout << "Inexistant"; }
          std::cout << std::endl;
          i += 1; }
        flag_a = false; }

      void Search(std::string bonjour)
      { if (bonjour.size() == 1 && static_cast<char>(bonjour[0]) >= '0')
        { char coucou = static_cast<char>(bonjour[0]);
          coucou -= '0';
          if (coucou < 8)
          { if (!(names[coucou][0].empty()))
            { std::cout << "first name: " << names[coucou][0] << std::endl; }
            else
            { std::cout << "first name: Inexistant" << std::endl; }
            if (!(names[coucou][1].empty()))
            { std::cout << "last name: " << names[coucou][1] << std::endl; }
            else
            { std::cout << "last name: Inexistant" << std::endl; }
            if (!(names[coucou][2].empty()))
            { std::cout << "nickname: " << names[coucou][2] << std::endl; }
            else
            { std::cout << "nickname: Inexistant" << std::endl; }
            if (!(names[coucou][3].empty()))
            { std::cout << "login: " << names[coucou][3] << std::endl; }
            else
            { std::cout << "login: Inexistant" << std::endl; }
            if (!(names[coucou][4].empty()))
            { std::cout << "postal address: " << names[coucou][4] << std::endl; }
            else
            { std::cout << "postal address: Inexistant" << std::endl; }
            if (!(names[coucou][5].empty()))
            { std::cout << "email address: " << names[coucou][5] << std::endl; }
            else
            { std::cout << "email address: Inexistant" << std::endl; }
            if (!(names[coucou][6].empty()))
            { std::cout << "phone number: " << names[coucou][6] << std::endl; }
            else
            { std::cout << "phone number: Inexistant" << std::endl; }
            if (!(names[coucou][7].empty()))
            { std::cout << "birthday date: " << names[coucou][7] << std::endl; }
            else
            { std::cout << "birthday date: Inexistant" << std::endl; }
            if (!(names[coucou][8].empty()))
            { std::cout << "favorite meal: " << names[coucou][8] << std::endl; }
            else
            { std::cout << "favorite meal: Inexistant" << std::endl; }
            if (!(names[coucou][9].empty()))
            { std::cout << "underwear color: " << names[coucou][9] << std::endl; }
            else
            { std::cout << "underwear color: Inexistant" << std::endl; }
            if (!(names[coucou][10].empty()))
            { std::cout << "darkest secret: " << names[coucou][10] << std::endl; }
            else
            { std::cout << "darkest secret: Inexistant" << std::endl; }}
          else
          { std::cout << "Index immpossible (0 à 7 supporté)." << std::endl; }}
      else
      { std::cout << "Index impossible (0 à 7 supporté)." << std::endl; }
      flag_a = true; }

      bool Sflag()
      { return (flag_s); }

      bool Aflag()
      { return (flag_a); }};

  template<class T>
  int Repertoire<T>::count = 0;
  template<class T>
  bool Repertoire<T>::flag_a = true;
  template<class T>
  bool Repertoire<T>::flag_s = true;

  class Trait : private Repertoire<Trait>
  { public:
    using Repertoire<Trait>::Search;
    using Repertoire<Trait>::Display;
    using Repertoire<Trait>::Add; };
#endif
