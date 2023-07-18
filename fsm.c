#include "fsm.h"

void fsmInvokeEvent(
    fsm_t *fsm,
    uint8_t eventIDno) {

    uint8_t i = 0;

    // now searching for the correct table entry
    for(i = 0; i < fsm->NtableEntries; i++) {    

        // continue loop if current state does not macht
        if(fsm->table[i].currentState != fsm->currentState) {
            continue;
        }
        
        // continue loop if the event does not match
        if(fsm->table[i].eventIDno != eventIDno) {
            continue;
        }
        
        // execute state transistion action
        fsm->table[i].action();

        // update current state with new state
        fsm->currentState = fsm->table[i].nextState;
        
        // entry has been found stop search
        break;
    }
}

void fsmRoutine(fsm_t *fsm)
{   
    fsm->currentState();
}

void fsmNoAction();

void fsmInit(
    fsm_t *fsm,
    fsmTableEntry_t *table,
    uint8_t noOfTableEntries,
    fsmState_t entryState)
{
    fsm->NtableEntries = noOfTableEntries;
    fsm->table = table;
    fsm->currentState = entryState;
}
