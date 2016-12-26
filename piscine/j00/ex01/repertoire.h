/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:29:29 by jpepin            #+#    #+#             */
/*   Updated: 2016/12/26 11:51:59 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REP_H
#define REP_H
  #include <string>

  template <class T>
  class Repertoire
  { private:
      static int count;
      static bool flag;
      std::string names[8][11];

    public:
      void Add(std::string bonjour)
      { if (count == 88)
        { std::cout << "Le répertoire ne peut pas avoir plus de 8 noms." << std::endl;
          return; }
        names[count / 11][count % 11] = bonjour;
        if (!((count + 1) % 11))
        { std::cout << "Un nouveau champ complet a été ajouté au répertoire. at::" << count << std::endl;
          std::cout << "first name: " << names[count / 11][count - 10] << std::endl;
          std::cout << "last name: " << names[count / 11][count - 9] << std::endl;
          std::cout << "nickname: " << names[count / 11][count - 8] << std::endl;
          std::cout << "login: " << names[count / 11][count - 7] << std::endl;
          std::cout << "postal address: " << names[count / 11][count - 6] << std::endl;
          std::cout << "email address: " << names[count / 11][count - 5] << std::endl;
          std::cout << "phone number: " << names[count / 11][count - 4] << std::endl;
          std::cout << "birthday date: " << names[count / 11][count - 3] << std::endl;
          std::cout << "favorite meal: " << names[count / 11][count - 2] << std::endl;
          std::cout << "underwear color: " << names[count / 11][count - 1] << std::endl;
          std::cout << "darkest secret: " << names[count / 11][count] << std::endl; }
        count++; }

      void Display(void)
      { int i = 0;
        while (i < 8)
        { if (!(names[i][0].empty()))
          { if (!(names[i][0].empty()))
            { std::cout << names[i][0]; }
            else
            { break; }
            if (!(names[i][1].empty()))
            { std::cout << names[i][1]; }
            else
            { break; }
            if (!(names[i][2].empty()))
            { std::cout << names[i][2]; }
            else
            { break; }}
          else
          { break; }
          std::cout << std::endl;
          i += 1; }
        std::cout << std::endl; }

      void Search(std::string bonjour)
      { if (bonjour.size() == 1 && static_cast<char>(bonjour[0]) >= '0')
        { char coucou = static_cast<char>(bonjour[0]);
          coucou -= '0';
          if (coucou < 8)
          { if (!(names[coucou][0].empty()))
            { std::cout << "first name: " << names[coucou][0] << std::endl; }
            else
            { std::cout << "first name: Non attribué" << std::endl; }
            if (!(names[coucou][1].empty()))
            { std::cout << "last name: " << names[coucou][1] << std::endl; }
            else
            { std::cout << "last name: Non attribué" << std::endl; }
            if (!(names[coucou][2].empty()))
            { std::cout << "nickname: " << names[coucou][2] << std::endl; }
            else
            { std::cout << "nickname: Non attribué" << std::endl; }
            if (!(names[coucou][3].empty()))
            { std::cout << "login: " << names[coucou][3] << std::endl; }
            else
            { std::cout << "login: Non attribué" << std::endl; }
            if (!(names[coucou][4].empty()))
            { std::cout << "postal address: " << names[coucou][4] << std::endl; }
            else
            { std::cout << "postal address: Non attribué" << std::endl; }
            if (!(names[coucou][5].empty()))
            { std::cout << "email address: " << names[coucou][5] << std::endl; }
            else
            { std::cout << "email address: Non attribué" << std::endl; }
            if (!(names[coucou][6].empty()))
            { std::cout << "phone number: " << names[coucou][6] << std::endl; }
            else
            { std::cout << "phone number: Non attribué" << std::endl; }
            if (!(names[coucou][7].empty()))
            { std::cout << "birthday date: " << names[coucou][7] << std::endl; }
            else
            { std::cout << "birthday date: Non attribué" << std::endl; }
            if (!(names[coucou][8].empty()))
            { std::cout << "favorite meal: " << names[coucou][8] << std::endl; }
            else
            { std::cout << "favorite meal: Non attribué" << std::endl; }
            if (!(names[coucou][9].empty()))
            { std::cout << "underwear color: " << names[coucou][9] << std::endl; }
            else
            { std::cout << "underwear color: Non attribué" << std::endl; }
            if (!(names[coucou][10].empty()))
            { std::cout << "darkest secret: " << names[coucou][10] << std::endl; }
            else
            { std::cout << "darkest secret: Non attribué" << std::endl; }}
          else
          { std::cout << "Index immpossible (0 à 7 supporté)." << std::endl; }}
        else
        { std::cout << "Index impossible (0 à 7 supporté)." << std::endl; }}

      bool Aflag()
      { return (flag); }};

  template<class T>
  int Repertoire<T>::count = 0;
  template<class T>
  bool Repertoire<T>::flag = true;

  class Trait : private Repertoire<Trait>
  { public:
    using Repertoire<Trait>::Search;
    using Repertoire<Trait>::Display;
    using Repertoire<Trait>::Add; };
#endif
