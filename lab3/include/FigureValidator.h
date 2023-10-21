#ifndef LABS_OOP_FIGUREVALIDATOR_H
#define LABS_OOP_FIGUREVALIDATOR_H

#include "IFigureValidator.h"
#include "SquareValidator.h"
#include "RombValidator.h"
#include "RectangleValidator.h"
#include <vector1.hpp>


class FigureValidator : public IFigureValidator {
    static Vector<IFigureValidator> _validators;

public:
    static void Validate(const std::type_info &type, Vector<Point> points) {
        for (size_t i = 0; i < FigureValidator::_validators.getSize(); i++) {
            auto currentValidator = FigureValidator::_validators[i];

            if (currentValidator.IsAllowedFor(type)) {
                currentValidator.Validate(points);
            }
        }
    }  

};


Vector<IFigureValidator> FigureValidator::_validators = {
        RectangleValidator(), SquareValidator(), RombValidator()};

#endif  // LABS_OOP_FIGUREVALIDATOR_H
