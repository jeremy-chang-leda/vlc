/*
 * AbstractAdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2010 - 2011 Klagenfurt University
 *
 * Created on: Aug 10, 2010
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef ABSTRACTADAPTATIONLOGIC_H_
#define ABSTRACTADAPTATIONLOGIC_H_

#include "adaptationlogic/IAdaptationLogic.h"
#include "http/Chunk.h"
#include "mpd/MPD.h"
#include "mpd/Period.h"
#include "mpd/Representation.h"

struct stream_t;

namespace dash
{
    namespace logic
    {
        class AbstractAdaptationLogic : public IAdaptationLogic
        {
            public:
                AbstractAdaptationLogic             (mpd::MPD *mpd);
                virtual ~AbstractAdaptationLogic    ();
                virtual void reset                  ();

                virtual dash::http::Chunk*  getNextChunk            (Streams::Type);

                virtual void                updateDownloadRate     (size_t, mtime_t);

            protected:
                dash::mpd::MPD         *mpd;
                dash::mpd::Period      *currentPeriod;
                size_t                  count;
                mpd::Representation    *prevRepresentation;
        };
    }
}

#endif /* ABSTRACTADAPTATIONLOGIC_H_ */
