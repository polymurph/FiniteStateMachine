#ifndef _FSM_H_
#define _FSM_H_

#include <stdint.h>

/**
 * @brief Finite state machine function pointer typedef
 */
typedef void (*fsmState_t)(void);

/**
 * @brief Action typedef
 */
typedef void (*fsmAction_t)(void);

/**
 * @struct fsmTableEntry_t
 * This is a table entry typedef struct
 * 
 * @var fsmTableEntry_t::currentState
 *  The current state of the finite state machine.
 * 
 * @var fsmTableEntry_t::nextState
 *  The function pointer to the next state.
 * 
 * @var fsmTableEntry_t:eventIDno
 *  The event ID number which invokes this state transistion.
 * 
 * @var fsmTableEntry_t::action
 *  The function pointer to the action to be performed for this state transition.
 */
typedef struct{
    fsmState_t currentState;
    fsmState_t nextState;
    uint8_t eventIDno;
    fsmAction_t action;
} fsmTableEntry_t;

/**
 * @struct fsm_t
 *  The finite state machine object.
 * 
 * @var fsm_t::NtableEntries
 *  The number of state transitions inside the table.
 * 
 * @var fsm_t::*table pointer to the table containing all the state transisions.
 * 
 * @var fsm_t::currentState
 *  The current state of the finire state machine.
 */
typedef struct{
    uint8_t NtableEntries;
    fsmTableEntry_t *table;
    fsmState_t currentState;
} fsm_t;

/**
 * @brief Invokes an event.
 * 
 * @param fsm The pointer to the finite state machine object.
 * @param eventIDno The event ID number of the event to be invoked.
 */
void fsmInvokeEvent(
    fsm_t *fsm,
    uint8_t eventIDno);

/**
 * @brief Finite state machine routine.
 * 
 * This funtion runs the finite state machine that is passed by pointer.
 * This function can be called in a loop or thread.
 * 
 * @param *fsm pointer to the finite state machine object.
 */
void fsmRoutine(fsm_t *fsm)

/**
 * @brief No state transision action.
 * 
 * This function can be used as a blank if no action is needed when
 * transitioning to a new state on a given event.
 * 
 */
void fsmNoAction();

/**
 * @brief Finite state machine object initializer.
 * 
 * It updates the given finite state machine object with all the settings and
 * defines the current state of the finite state machine to be the entry state.
 * 
 * @param *fsm pointer to the finite state machine object.
 * @param table pointer to state stransistion table.
 * @param noOfTableEntries The ammoubt of table entries.
 * @param entryState The beginning state of the finite state machine.
 */
void fsmInit(
    fsm_t *fsm,
    fsmTableEntry_t *table,
    uint8_t noOfTableEntries,
    fsmState_t entryState);

#endif