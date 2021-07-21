import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

class popup(Gtk.MessageDialog):
    def __init__(self, parent):
        super().__init__(parent, 0, Gtk.MessageType.QUESTION,
            Gtk.ButtonsType.YES_NO, "No Subtitles found in your Language.")
        self.format_secondary_text("Would you like to check other languages?")
        
        self.connect('response', self._close_on_response)
    
    def _close_on_response(self, *_):
        self.close()
    
    def run_and_get_response(self):
        response = self.run()
        
        while Gtk.events_pending():
            Gtk.main_iteration()
        self.destroy()
        
        return response

def ext():
    dialog = popup(None)
    
    response = dialog.run_and_get_response()
    if response == Gtk.ResponseType.YES:
        print("QUESTION dialog closed by clicking YES button")
        return 1
    elif response == Gtk.ResponseType.NO:
        print("QUESTION dialog closed by clicking NO button")
        return -1

if __name__ == '__main__':
    ext()
