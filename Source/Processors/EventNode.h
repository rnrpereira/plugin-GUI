/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2012 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __EVENTNODE_H_9B67A789__
#define __EVENTNODE_H_9B67A789__

#include "../../JuceLibraryCode/JuceHeader.h"
#include "GenericProcessor.h"
#include "Editors/EventNodeEditor.h"

/**
  
  Generates events at regular intervals.

  @see GenericProcessor, EventNodeEditor

*/

class EventNode : public GenericProcessor

{
public:
	
	EventNode();
	~EventNode();
	
	void process(AudioSampleBuffer &buffer, MidiBuffer &midiMessages, int& nSamples);
	void setParameter (int parameterIndex, float newValue);

	bool isSource() {return true;}

    int getDefaultNumOutputs() {return 0;}

    void updateSettings();

	AudioProcessorEditor* createEditor();
	
private:

	float accumulator;
	float Hz;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EventNode);

};






#endif  // __EVENTNODE_H_9B67A789__
