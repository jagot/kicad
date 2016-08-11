#ifndef __sim_plot_frame__
#define __sim_plot_frame__

/**
@file
Subclass of SIM_PLOT_FRAME_BASE, which is generated by wxFormBuilder.
*/

#include "sim_plot_frame_base.h"

#include "kiway_player.h"

#include <netlist_exporters/netlist_exporter_pspice.h>
//// end generated include

class SPICE_SIMULATOR;
class NETLIST_EXPORTER_PSPICE;

/** Implementing SIM_PLOT_FRAME_BASE */
class SIM_PLOT_FRAME : public SIM_PLOT_FRAME_BASE
{
	public:
		/** Constructor */
		SIM_PLOT_FRAME(KIWAY *aKiway, wxWindow* parent );
		~SIM_PLOT_FRAME();

		void SetSchFrame( SCH_EDIT_FRAME* schFrame )
		{
			m_schematicFrame = schFrame;
		}

		void StartSimulation();

	private:

		SCH_EDIT_FRAME *m_schematicFrame;
		NETLIST_EXPORTER_PSPICE *m_exporter;
		SPICE_SIMULATOR *m_simulator;

	//// end generated class members
};

#endif // __sim_plot_frame__
