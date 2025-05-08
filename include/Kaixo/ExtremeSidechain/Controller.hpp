#pragma once

// ------------------------------------------------

#include <JuceHeader.h>

// ------------------------------------------------

namespace Kaixo {

    // ------------------------------------------------

    class Controller : public juce::AudioProcessor {
    public:

        // ------------------------------------------------

        Controller();

        // ------------------------------------------------

        void prepareToPlay(double sampleRate, int samplesPerBlock) override {}
        void releaseResources() override {}

        // ------------------------------------------------

        bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

        // ------------------------------------------------

        void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

        // ------------------------------------------------

        juce::AudioProcessorEditor* createEditor() override { return nullptr; }
        bool hasEditor() const override { return false; }

        // ------------------------------------------------

        const juce::String getName() const override { return JucePlugin_Name; }

        bool acceptsMidi() const override { return false; }
        bool producesMidi() const override { return false; }
        double getTailLengthSeconds() const override { return 0; }

        // ------------------------------------------------

        int  getNumPrograms() override { return 0; }
        int  getCurrentProgram() override { return 0; }
        void setCurrentProgram(int index) override {}
        void changeProgramName(int index, const juce::String& newName) override {}

        const juce::String getProgramName(int index) override { return {}; }

        // ------------------------------------------------

        void getStateInformation(juce::MemoryBlock& destData) override {}
        void setStateInformation(const void* data, int sizeInBytes) override {}

        // ------------------------------------------------

    };

    // ------------------------------------------------

}

// ------------------------------------------------
