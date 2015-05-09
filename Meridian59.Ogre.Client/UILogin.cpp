#include "stdafx.h"

namespace Meridian59 { namespace Ogre
{
	void ControllerUI::Login::Initialize()
	{
		// setup references to children from xml nodes
		Window = static_cast<CEGUI::FrameWindow*>(guiRoot->getChild(UI_NAME_LOGIN_WINDOW));
		Server = static_cast<CEGUI::Combobox*>(Window->getChild(UI_NAME_LOGIN_SERVER));
		Username = static_cast<CEGUI::Editbox*>(Window->getChild(UI_NAME_LOGIN_USERNAME));
		Password = static_cast<CEGUI::Editbox*>(Window->getChild(UI_NAME_LOGIN_PASSWORD));
		
		Connect = static_cast<CEGUI::PushButton*>(Window->getChild(UI_NAME_LOGIN_CONNECT));
		Options = static_cast<CEGUI::PushButton*>(Window->getChild(UI_NAME_LOGIN_OPTIONS));

		OgreClientConfig^ config = OgreClient::Singleton->Config;

		// fill servers
		for each(ConnectionInfo^ coninfo in config->Connections)
			Server->addItem(new ::CEGUI::ListboxTextItem(StringConvert::CLRToCEGUI(coninfo->Name)));

		// subscribe server selection change
		Server->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(UICallbacks::Login::OnServerChanged));
		
		// subscribe return on passwordbox
		Password->subscribeEvent(CEGUI::Editbox::EventTextAccepted, CEGUI::Event::Subscriber(UICallbacks::Login::OnPasswordTextAccepted));

		// subscribe buttons
		Connect->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(UICallbacks::Login::OnConnectClicked));
		Options->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(UICallbacks::Login::OnOptionsClicked));
	};

	void ControllerUI::Login::Destroy()
	{
	};
	
	bool UICallbacks::Login::OnServerChanged(const CEGUI::EventArgs& e)
	{
		const CEGUI::WindowEventArgs& args	= (const CEGUI::WindowEventArgs&)e;
		const CEGUI::Combobox* combobox		= (const CEGUI::Combobox*)args.window;

		OgreClient::Singleton->Config->SelectedConnectionIndex = (int)combobox->getItemIndex(combobox->getSelectedItem());

		ControllerUI::Login::Username->setText(
			StringConvert::CLRToCEGUI(OgreClient::Singleton->Config->SelectedConnectionInfo->Username));

		ControllerUI::Login::Password->setText(
			StringConvert::CLRToCEGUI(OgreClient::Singleton->Config->SelectedConnectionInfo->Password));

		return true;
	};
	
	bool UICallbacks::Login::OnPasswordTextAccepted(const CEGUI::EventArgs& e)
	{
		const CEGUI::WindowEventArgs& args	= (const CEGUI::WindowEventArgs&)e;
		const CEGUI::Editbox* editbox		= (const CEGUI::Editbox*)args.window;

		OgreClient::Singleton->Config->SelectedConnectionInfo->Username =
			StringConvert::CEGUIToCLR(ControllerUI::Login::Username->getText());

		OgreClient::Singleton->Config->SelectedConnectionInfo->Password =
			StringConvert::CEGUIToCLR(ControllerUI::Login::Password->getText());

		OgreClient::Singleton->Connect();

		return true;
	};

	bool UICallbacks::Login::OnConnectClicked(const CEGUI::EventArgs& e)
	{
		const CEGUI::WindowEventArgs& args	= (const CEGUI::WindowEventArgs&)e;
		const CEGUI::PushButton* btn		= (const CEGUI::PushButton*)args.window;

		OgreClient::Singleton->Config->SelectedConnectionInfo->Username =
			StringConvert::CEGUIToCLR(ControllerUI::Login::Username->getText());

		OgreClient::Singleton->Config->SelectedConnectionInfo->Password =
			StringConvert::CEGUIToCLR(ControllerUI::Login::Password->getText());

		OgreClient::Singleton->Connect();

		return true;
	};

	bool UICallbacks::Login::OnOptionsClicked(const CEGUI::EventArgs& e)
	{
		const CEGUI::WindowEventArgs& args	= (const CEGUI::WindowEventArgs&)e;
		const CEGUI::PushButton* btn		= (const CEGUI::PushButton*)args.window;

		ControllerUI::ToggleVisibility(ControllerUI::Options::Window);

		return true;
	};
};};