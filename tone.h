#ifndef TONE_H
#define TONE_H

void play_tone(float, float);

struct Voice {
    /**
     * Microseconds of a half period
     */
    long us_half_period;

    /**
     * Microseconds left until next toggle
     */
    long us_toggle;

    /**
     * Current microseconds left until note stops playing
     */
    long us_end;

    /**
     * The last state of the buzzer
     */
    int last_state;

    /**
     * @var bool
     * Whether the voice is done
     */
    bool voice_end;

    /**
     * Whether it's resting (Not playing note)
     * Denoted by a zero frequency
     */
    bool is_resting;

    /**
     * Buzzer for this voice to play on
     */
    int buzzer_pin;

    /**
     * The current index of the frequncy array we are playing.
     * Always increments
     */
    int song_index;

    /**
     * Array containing the frequencies of the song to play
     * In order.
     */
    float* freq_arr;

    /**
     * How long to play each of the above frequencies
     */
    float* note_lengths;
};

class Player
{
    public:
    struct Voice voices[3];
    int total_voices;
    int last_cycle;
    int cycle_length;
    int song_end_index;
    bool song_end;
    Player();
    void assign_voice(float* freq, float* note_lengths, int buzzer_pin);
    void update_next_note(int voice_index);
    void toggle_voice_buzzer(int voice_index);
    void decrement_times(int voice_index);
    bool check_voice_end(int voice_index);
    void cycle();
    void start();
};

#endif