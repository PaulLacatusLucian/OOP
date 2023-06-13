#include "Repository.h"
#include <algorithm>

namespace Repository {

    InMemoryRepository::InMemoryRepository() {

        Domain::Elektroscooter a("AAA", 12, "bolt", "25-05-2023", "Decebal", "geparkt");
        Domain::Elektroscooter b("BBB", 13, "bolt", "08-11-2023", "Kogalniceanu", "geparkt");
        Domain::Elektroscooter c("CCC", 14, "uber", "13-11-2023", "Horea", "geparkt");
        Domain::Elektroscooter d("DDD", 15, "bolt", "11-12-2023", "Iuliu Maniu", "geparkt");
        Domain::Elektroscooter e("EEE", 16, "bolt", "11-12-2023", "Albota", "reserviert");
        Domain::Elektroscooter f("FFF", 17, "uber", "11-12-2023", "Bucium", "geparkt");
        Domain::Elektroscooter g("GGG", 18, "bolt", "11-11-2023", "Artelor", "geparkt");
        Domain::Elektroscooter h("HHH", 19, "bolt", "11-11-2021", "Muncii", "geparkt");
        Domain::Elektroscooter i("III", 20, "uber", "11-11-2022", "Fabricii de zahar", "geparkt");
        Domain::Elektroscooter j("JJJ", 20, "uber", "11-11-2022", "Remorcii de zahar", "geparkt");
        {
            inMemoryRepo.push_back(a);
            inMemoryRepo.push_back(b);
            inMemoryRepo.push_back(c);
            inMemoryRepo.push_back(d);
            inMemoryRepo.push_back(e);
            inMemoryRepo.push_back(f);
            inMemoryRepo.push_back(g);
            inMemoryRepo.push_back(h);
            inMemoryRepo.push_back(i);
            inMemoryRepo.push_back(j);


        }
    }

    void InMemoryRepository::update(Domain::Elektroscooter elektroscooter) {
        for (auto &scooter: inMemoryRepo) {
            if (scooter.get_id() == elektroscooter.get_id()) {
                scooter = elektroscooter;
                break;
            }
        }
    }

    vector<Domain::Elektroscooter> InMemoryRepository::readFromFile() {
        return inMemoryRepo;
    }


    void InMemoryRepository::create(Domain::Elektroscooter elektroscooter) {
        if (!searchForID(elektroscooter.get_id())) {
            inMemoryRepo.push_back(elektroscooter);
        } else {
            update(elektroscooter);
        }
    }

    void InMemoryRepository::remove(Domain::Elektroscooter elektroscooter) {
        if (!searchForID(elektroscooter.get_id())) {
            throw std::invalid_argument("Der Scooter existiert nicht");
        } else {
            for (auto it = inMemoryRepo.begin(); it != inMemoryRepo.end(); ++it) {
                if (elektroscooter.get_id() == it->get_id()) {
                    inMemoryRepo.erase(it);
                    break;
                }
            }
        }
    }

    bool InMemoryRepository::searchForID(const std::string &id) {
        auto it = std::find_if(inMemoryRepo.begin(), inMemoryRepo.end(),
                               [id](const Domain::Elektroscooter &scooter) {
                                   return scooter.get_id() == id;
                               });

        return (it != inMemoryRepo.end());
    }

    std::vector<Domain::Elektroscooter> CSVFileRepository::readFromFile() {
        std::ifstream file("scooters.csv");
        std::vector<Domain::Elektroscooter> scootersVector;
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string modell, kilometerStr, inbetriebnahmedatum, letzterStandort, aktuellerZustand, id;

                if (std::getline(iss >> std::ws, id, ',') && std::getline(iss >> std::ws, modell, ',') &&
                    std::getline(iss >> std::ws, inbetriebnahmedatum, ',') &&
                    std::getline(iss >> std::ws, kilometerStr, ',') &&
                    std::getline(iss >> std::ws, letzterStandort, ',') &&
                    std::getline(iss >> std::ws, aktuellerZustand)) {
                    int kilometer = std::stoi(kilometerStr);
                    Domain::Elektroscooter aux(id, kilometer, modell, inbetriebnahmedatum, letzterStandort,
                                               aktuellerZustand);
                    scootersVector.push_back(aux);
                }
            }
            file.close();
        } else {
            throw std::exception();
        }

        return scootersVector;
    }

    void InMemoryRepository::writeToFile(std::vector<Domain::Elektroscooter> &scootersVector) {
        inMemoryRepo = scootersVector;
    }

    void InMemoryRepository::addToReservierteScooters(const string &id) {
        for (auto &scooter: inMemoryRepo) {
            if (scooter.get_id() == id) {
                reservierteScooters.push_back(scooter);
                break;
            }
        }
    }

    vector<Domain::Elektroscooter> InMemoryRepository::getReservierteScooters() {
        if (!reservierteScooters.empty())
            return reservierteScooters;
        return reservierteScooters;
        throw invalid_argument("No scooters were reserved!");
    }

    void CSVFileRepository::writeToFile(std::vector<Domain::Elektroscooter> &scootersVector) {
        std::ofstream file("scooters.csv");

        if (file.is_open()) {
            for (const auto &scooter: scootersVector) {
                file << scooter.get_id() << ", "
                     << scooter.get_modell() << ", "
                     << scooter.get_inbetriebnahmedatum() << ", "
                     << scooter.get_kilometer() << ", "
                     << scooter.get_letzterStandort() << ", "
                     << scooter.get_aktuellerZustand();
                file << std::endl;
            }
            file.close();
        } else {
            throw std::exception();
        }
    }

    void CSVFileRepository::create(Domain::Elektroscooter elektroscooter) {
        bool found = searchForID(elektroscooter.get_id());
        auto scootersVector = readFromFile();

        if (found) {
            for (auto &scooter: scootersVector) {
                if (scooter.get_id() == elektroscooter.get_id()) {
                    scooter = elektroscooter;
                    break;
                }
            }
        } else {
            scootersVector.push_back(elektroscooter);
        }

        writeToFile(scootersVector);
    }

    void CSVFileRepository::remove(Domain::Elektroscooter elektroscooter) {
        bool found = searchForID(elektroscooter.get_id());
        auto scootersVector = readFromFile();

        if (found) {
            auto it = std::find_if(scootersVector.begin(), scootersVector.end(),
                                   [&](const Domain::Elektroscooter &scooter) {
                                       return scooter.get_id() == elektroscooter.get_id();
                                   });

            if (it != scootersVector.end()) {
                scootersVector.erase(it);
            } else {
                throw std::invalid_argument("No element was deleted");
            }
        } else {
            throw std::invalid_argument("No element was found");
        }

        writeToFile(scootersVector);
    }

    bool CSVFileRepository::searchForID(const std::string &id) {
        auto scooterVector = readFromFile();
        auto it = std::find_if(scooterVector.begin(), scooterVector.end(),
                               [id](const Domain::Elektroscooter &scooter) {
                                   return scooter.get_id() == id;
                               });

        return (it != scooterVector.end());
    }

    void CSVFileRepository::update(Domain::Elektroscooter elektroscooter) {
        auto scooters = readFromFile();
        for (auto &scooter: scooters) {
            if (scooter.get_id() == elektroscooter.get_id()) {
                scooter = elektroscooter;
                break;
            }
        }
    }

    void CSVFileRepository::addToReservierteScooters(const string &id) {
        auto scooters = readFromFile();
        for (auto &scooter: scooters) {
            if (scooter.get_id() == id) {
                reservierteScooters.push_back(scooter);
                break;
            }
        }
    }

    vector<Domain::Elektroscooter> CSVFileRepository::getReservierteScooters() {
        if (!reservierteScooters.empty())
            return reservierteScooters;
        throw invalid_argument("No scooters were reserved!");
    }
}