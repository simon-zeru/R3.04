#ifndef USAGER_H
#define USAGER_H

#include <string>

class Usager {
public:
    Usager(const std::string login, const std::string groupe);
    const std::string & getLogin() const;
    const std::string & getGroupe() const;

    friend std::ostream &operator<<(std::ostream &sortie, const Usager &usager);


private:
    const std::string m_login;
    const std::string m_groupe;
};

#endif /* USAGER_H */

