#include "main.h"

bool saveCovarianceInPostgreSQL(std::vector<std::vector<double>> &covariances, size_t firstSampleTime, PGconn *conn){

    PGresult *res = PQexec(conn, "BEGIN");

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Errore durante l'inizio della transazione: " << PQresultErrorMessage(res) << std::endl;
        PQclear(res);
        return false;
    }

    PQclear(res);       

    for (size_t i=0; i<covariances.size(); i++) {
        for (size_t j=0; j<covariances[i].size(); j++) {

            std::string query = "INSERT INTO averageTable (sensorID1, sensorID2, value, firstSampleTime, lastSampleTime) VALUES (SAC"
                                + std::to_string(i) + ", SAC" + std::to_string(j) + ", " + std::to_string(covariances[i][j]) + ", " 
                                + std::to_string(firstSampleTime) + ", " + std::to_string(firstSampleTime + W) + ")";
        
            res = PQexec(conn, query.c_str());
            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                std::cerr << "Errore durante l'esecuzione della query: " << PQresultErrorMessage(res) << std::endl;
                PQclear(res);
                return false;
            }
            PQclear(res);
        }
    }

    //Concludi la transazione
    res = PQexec(conn, "COMMIT");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Errore durante la conclusione della transazione: " << PQresultErrorMessage(res) << std::endl;
        return false;
    }
    PQclear(res);
    return true;
}