#ifndef USAGER_H
#define USAGER_H
#include <string>

class Usager {

private:
    std::string m_login;
    std::string m_groupe;

public:
    Usager(const std::string &login, const std::string &groupe)
        : m_login(login),
          m_groupe(groupe) {
    }

    const std::string & getLogin() const {
        return m_login;
    }

    void setLogin(const std::string &login) {
        this->m_login = login;
    }

    const std::string & getGroupe() const {
        return m_groupe;
    }

    void setGroupe(const std::string &groupe) {
        this->m_groupe = groupe;
    }

    friend std::ostream & operator<<(std::ostream &os, const Usager &usager);
};

#endif /* USAGER_H */

