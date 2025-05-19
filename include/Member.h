#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <ostream>

class Member {
public:
    Member(int id, const std::string& name);
    Member(const Member& other);
    Member& operator=(Member other);
    ~Member() = default;

    int getId() const;
    std::string getName() const;
    friend std::ostream& operator<<(std::ostream& os, const Member& m);
    void swap(Member& other);

private:
    int id_;
    std::string name_;
};

#endif // MEMBER_H
