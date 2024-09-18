#ifndef WORK_WITH_DOUBLES_H
#define WORK_WITH_DOUBLES_H

static const double EPS = 1e-8;

//------------------------------------------------------
//! Checks if number is negative or positive infinity
//!
//! @param [in] n double number
//!
//! @return True or False
//------------------------------------------------------
bool isInf(double n);

//-----------------------------
//! Checks if number is NaN
//!
//! @param [in] n double number
//!
//! @return True or False
//-----------------------------
bool isNan(double n);

//-----------------------------
//! Checks if number is finite
//!
//! @param [in] n double number
//!
//! @return True or False
//-----------------------------
bool isFinite(double n);

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if a is equal to b and False if a is not equal to b
//-----------------------------------------------------------------------
bool equatTwoDoubles (double a, double b);

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if a is greater than b and False if a is less than b
//-----------------------------------------------------------------------
bool compareGreaterTwoDoubles (double a, double b);

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if b is greater than a and False if b is less than a
//-----------------------------------------------------------------------
bool compareLessTwoDoubles (double a, double b);

#endif // WORK_WITH_DOUBLES_H
