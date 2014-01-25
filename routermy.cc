/*
 * routermy.cc
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

 

#include "routermy.h"
#include <algorithm>

Define_Module(Routermy);

void Routermy::initialize()
{
    std::vector<float> init_probs;
    float sum = 0;
    const char *dist = par("distances");
    cStringTokenizer tokenizer(dist);
    int idx = 0;
    while (tokenizer.hasMoreTokens()) {
        float f = atof(tokenizer.nextToken());
        sum += f;
        init_probs.push_back(f);
        idx++;
    }
    std::sort(this->probs.begin(), this->probs.end());
    if (sum!=1) error("%s %f %s\n","Error: string paramters don't have a 1 sum but ",sum, "found");
    if (idx!=gateSize("out")) error("%s %d %s\n","Error: string paramter size doesn't match with the outputs (",gateSize("out"),")");
    std::vector<float>::iterator it;
    float xsum = 0;
    for(it = init_probs.begin(); it != init_probs.end(); ++it) {
            float val =  (*it);
            xsum += val;
            this->probs.push_back(xsum);
    }
}

void Routermy::handleMessage(cMessage *msg)
{
    int outGateIndex = -1;  // by default we drop the message

    float num = dblrand();
    int idx = 0;
    std::vector<float>::iterator it;
    for(it = this->probs.begin(); it != this->probs.end(); ++it) {
        float val =  (*it);
        if (num<val) {
            outGateIndex = idx;
            break;
        }
        idx++;
    }

    // send out if the index is legal
    if (outGateIndex < 0 || outGateIndex >= gateSize("out"))
            error("Invalid output gate selected during routing");

    send(msg, "out", outGateIndex);

}
