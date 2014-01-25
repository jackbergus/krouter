/*
 * routermy.h
 * This file is part of krouter
 *
 * Copyright (C) 2014 - Giacomo Bergami
 *
 * krouter is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * krouter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with krouter. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __PROGETTOVUOTO_ROUTERMY_H_
#define __PROGETTOVUOTO_ROUTERMY_H_

#include <omnetpp.h>

/**
 * TODO - Generated class
 */
class Routermy : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    std::vector<float> probs;
};

#endif
