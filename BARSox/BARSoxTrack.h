#ifndef BARSOXTRACK_H
#define BARSOXTRACK_H

#include "BARSoxPositionNode.h"
#include "BARSoxNode.h"
#include <sox.h>
#include <vector>

#ifndef AUDIO_DRIVER
    #define AUDIO_DRIVER    "waveaudio"
#endif

/**
 * @brief The BARSoxTrack class handles data for one track.
 * A track contains only one kind of sound, repeated along beats.
 * @author Hugo Duprat [<a href="mailto:hugo.duprat@gmail.com">Contact</a>]
 * @date 3/08/2013
 *
 * @todo See if it would be useful to create an instance counter.
 */
class BARSoxTrack
{
    protected:
        unsigned int nBeats; /**< Number of beats of the pattern.*/
        unsigned int notesPerBeat; /**< Amount of notes per beat (1,2,4 or 8).*/

        std::vector<sox_sample_t> trackSoundBuffer; /**< Sound buffer for the track sound. */
        unsigned int masterVolume; /**< Master volume for the track. */
        std::vector< BARSoxNode<unsigned int> > volumeTrees; /**< Volume trees per beat for the track. */

        bool mute; /**< @c true if mute track, @c false otherwise. */

    public:
        BARSoxTrack();
        BARSoxTrack(const char* filename,unsigned int nBeats = 4, unsigned int notesPerBeat = 2, unsigned int masterVolume = 100);

        void updateVolumeTrees(unsigned int npbBegin, unsigned int npbEnd);
        void nBeatsChanged(unsigned int newVal);

        ~BARSoxTrack();
};

#endif // BARSOXTRACK_H
