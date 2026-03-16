#include"./MedicalRecord.h"
#include <string>
#ifndef PATIENT_H
#define PATIENT_H
class Patient {
  public:
    const int patientId;
    MedicalRecord record;
    string name ;
    static int admittedCount ;
    
    Patient() : Patient(admittedCount, "unknown"){}
    Patient(int id, string name ) : patientId(id), record(id), name(name) {
    admittedCount++;
  }
};
#endif