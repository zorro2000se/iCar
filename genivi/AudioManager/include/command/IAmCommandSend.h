/**
 * Copyright (C) 2012, BMW AG
 *
 * This file is part of GENIVI Project AudioManager.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *
 * \author Christian Mueller, christian.ei.mueller@bmw.de BMW 2011,2012
 *
 * \file
 * For further information see http://www.genivi.org/.
 *
 * THIS CODE HAS BEEN GENERATED BY ENTERPRISE ARCHITECT GENIVI MODEL. PLEASE CHANGE ONLY IN ENTERPRISE ARCHITECT AND GENERATE AGAIN
 */
#if !defined(EA_EA24D1A2_FDA1_4285_8606_7E77A080B4E9__INCLUDED_)
#define EA_EA24D1A2_FDA1_4285_8606_7E77A080B4E9__INCLUDED_

#include <vector>
#include <string>
#include "audiomanagertypes.h"

namespace am {
class IAmCommandReceive;
}

#include "IAmCommandReceive.h"

#define CommandSendVersion "1.0" 
namespace am {
	/**
	 * This interface handles all communication from the AudioManagerDaemon towards
	 * the system. It is designed in such a way that only callbacks with no return
	 * types are implemented. So when the CommandInterfacePlugins are designed in such
	 * a way that they broadcast signals to any node who is interested in the
	 * particular information (like signals on Dbus for example), more information can
	 * be retrieved via the CommandReceiveInterface.
	 * There are two rules that have to be kept in mind when implementing against this
	 * interface:\n
	 * \warning
	 * 1. CALLS TO THIS INTERFACE ARE NOT THREAD SAFE !!!! \n
	 * 2. YOU MAY NOT CALL THE CALLING INTERFACE DURING AN SYNCHRONOUS OR ASYNCHRONOUS
	 * CALL THAT EXPECTS A RETURN VALUE.\n
	 * \details
	 * Violation these rules may lead to unexpected behavior! Nevertheless you can
	 * implement thread safe by using the deferred-call pattern described on the wiki
	 * which also helps to implement calls that are forbidden.\n
	 * For more information, please check CAmSerializer
	 * @author Christian Mueller
	 * @created 07-Mar-2012 6:06:17 PM
	 */
	class IAmCommandSend
	{

	public:
		IAmCommandSend() {

		}

		virtual ~IAmCommandSend() {

		}

		/**
		 * returns the interface version as string.
		 * 
		 * @param version
		 */
		virtual void getInterfaceVersion(std::string& version) const =0;
		/**
		 * This command starts the interface, the plugin itself. This is not meant to
		 * start communication with the HMI itself. It is a good idea to implement here
		 * everything that sets up the basic communication like DbusCommunication etc...
		 * Be aware of side effects with systemd and socketbased communication!
		 * @return E_OK on success, E_UNKNOWN on error
		 * 
		 * @param commandreceiveinterface    pointer to the receive interface. Is used to
		 * call the audiomanagerdaemon
		 */
		virtual am_Error_e startupInterface(IAmCommandReceive* commandreceiveinterface) =0;
		/**
		 * This function will indirectly be called by the Controller and is used to start
		 * the Communication. Before this command, all communication will be ignored by
		 * the AudioManager.
		 * After the Plugin is ready, it will asynchronously answer with
		 * condfirmCommandReady, the handle that is handed over must be returned.
		 * 
		 * @param handle    the handle uniquely idenfies the request
		 */
		virtual void setCommandReady(const uint16_t handle) =0;
		/**
		 * This function will indirectly be called by the Controller and is used to stop
		 * the Communication. After this command, all communication will be ignored by the
		 * AudioManager. The plugin has to be prepared that either the power will be
		 * switched off or the Interface is started again with setCommandReady
		 * After the Plugin is ready to rundown, it will asynchronously answer with
		 * condfirmCommandRundown, the handle that is handed over must be returned.
		 * 
		 * @param handle    This handle uniquly idenfies the request
		 */
		virtual void setCommandRundown(const uint16_t handle) =0;
		/**
		 * Callback that is called when the number of connections change
		 * 
		 * @param mainConnection
		 */
		virtual void cbNewMainConnection(const am_MainConnectionType_s& mainConnection) =0;
		/**
		 * Callback that is called when the number of connections change
		 * 
		 * @param mainConnection
		 */
		virtual void cbRemovedMainConnection(const am_mainConnectionID_t mainConnection) =0;
		/**
		 * Callback that is called when the number of sinks change
		 * 
		 * @param sink
		 */
		virtual void cbNewSink(const am_SinkType_s& sink) =0;
		/**
		 * Callback that is called when the number of sinks change
		 * 
		 * @param sinkID
		 */
		virtual void cbRemovedSink(const am_sinkID_t sinkID) =0;
		/**
		 * Callback that is called when the number of sources change
		 * 
		 * @param source
		 */
		virtual void cbNewSource(const am_SourceType_s& source) =0;
		/**
		 * Callback that is called when the number of sources change
		 * 
		 * @param source
		 */
		virtual void cbRemovedSource(const am_sourceID_t source) =0;
		/**
		 * this callback is fired if the number of sink classes changed
		 */
		virtual void cbNumberOfSinkClassesChanged() =0;
		/**
		 * this callback is fired if the number of source classes changed
		 */
		virtual void cbNumberOfSourceClassesChanged() =0;
		/**
		 * This callback is called when the ConnectionState of a connection changed.
		 * 
		 * @param connectionID
		 * @param connectionState
		 */
		virtual void cbMainConnectionStateChanged(const am_mainConnectionID_t connectionID, const am_ConnectionState_e connectionState) =0;
		/**
		 * this callback indicates that a sinkSoundProperty has changed.
		 * 
		 * @param sinkID
		 * @param soundProperty
		 */
		virtual void cbMainSinkSoundPropertyChanged(const am_sinkID_t sinkID, const am_MainSoundProperty_s& soundProperty) =0;
		/**
		 * this callback indicates that a sourceSoundProperty has changed.
		 * 
		 * @param sourceID
		 * @param soundProperty
		 */
		virtual void cbMainSourceSoundPropertyChanged(const am_sourceID_t sourceID, const am_MainSoundProperty_s& soundProperty) =0;
		/**
		 * this callback is called when the availability of a sink has changed
		 * 
		 * @param sinkID
		 * @param availability
		 */
		virtual void cbSinkAvailabilityChanged(const am_sinkID_t sinkID, const am_Availability_s& availability) =0;
		/**
		 * this callback is called when the availability of source has changed.
		 * 
		 * @param sourceID
		 * @param availability
		 */
		virtual void cbSourceAvailabilityChanged(const am_sourceID_t sourceID, const am_Availability_s& availability) =0;
		/**
		 * this callback indicates a volume change on the indicated sink
		 * 
		 * @param sinkID
		 * @param volume
		 */
		virtual void cbVolumeChanged(const am_sinkID_t sinkID, const am_mainVolume_t volume) =0;
		/**
		 * this callback indicates a mute state change on a sink.
		 * 
		 * @param sinkID
		 * @param muteState
		 */
		virtual void cbSinkMuteStateChanged(const am_sinkID_t sinkID, const am_MuteState_e muteState) =0;
		/**
		 * is fired if a systemProperty changed
		 * 
		 * @param systemProperty
		 */
		virtual void cbSystemPropertyChanged(const am_SystemProperty_s& systemProperty) =0;
		/**
		 * This callback is fired if the timinginformation for a mainConnectionID changed
		 * 
		 * @param mainConnectionID
		 * @param time
		 */
		virtual void cbTimingInformationChanged(const am_mainConnectionID_t mainConnectionID, const am_timeSync_t time) =0;

	};
}
#endif // !defined(EA_EA24D1A2_FDA1_4285_8606_7E77A080B4E9__INCLUDED_)
