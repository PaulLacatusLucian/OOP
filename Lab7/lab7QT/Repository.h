#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Elektroscooter.h"
#include <vector>
#include <fstream>
#include <sstream>

namespace Repository {
    class CrudRepository {
    public:
        virtual void create(Domain::Elektroscooter elektroscooter)=0;
        virtual void remove(Domain::Elektroscooter elektroscooter)=0;
        virtual void update(Domain::Elektroscooter elektroscooter)=0;
        virtual void writeToFile(vector<Domain::Elektroscooter>& scootersVector)=0;
        virtual  vector<Domain::Elektroscooter> readFromFile()=0;
        virtual void addToReservierteScooters(const string &id)=0;
        virtual vector<Domain::Elektroscooter> getReservierteScooters()=0;

    };

    class InMemoryRepository : public CrudRepository {
    private:
        vector<Domain::Elektroscooter> inMemoryRepo;
        vector<Domain::Elektroscooter> reservierteScooters;

    public:
        InMemoryRepository();


        void update(Domain::Elektroscooter elektroscooter) override;
        void create(Domain::Elektroscooter elektroscooter) override;
        void remove(Domain::Elektroscooter elektroscooter) override;
        bool searchForID(const std::string& id);
        vector<Domain::Elektroscooter> readFromFile();
        void writeToFile(vector<Domain::Elektroscooter>& scootersVector) override;
        void addToReservierteScooters(const string &id) override;
        vector<Domain::Elektroscooter> getReservierteScooters() override;
    };

    class CSVFileRepository : public CrudRepository {
    private:
        vector<Domain::Elektroscooter> reservierteScooters;

    public:

        CSVFileRepository() = default;

        vector<Domain::Elektroscooter> readFromFile();
        void writeToFile(std::vector<Domain::Elektroscooter>& scootersVector);
        void create(Domain::Elektroscooter elektroscooter) override;
        void remove(Domain::Elektroscooter elektroscooter) override;
        void update(Domain::Elektroscooter elektroscooter) override;
        bool searchForID(const std::string& id);
        void addToReservierteScooters(const string &id) override;
        vector<Domain::Elektroscooter> getReservierteScooters() override;
    };
}

#endif // REPOSITORY_H
