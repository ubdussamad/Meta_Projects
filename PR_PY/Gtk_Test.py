import os,sys,apt,time,gi
gi.require_version('Gtk','3.0')
from gi.repository import Gtk
from subprocess import call


if not apt.Cache()['nautilus-actions'].is_installed:
    print("Nautilus Action Tool is not installed, You can install it by typing: \n sudo apt-get install nautilus-actions")
    if str(input("Would you like to?(Y/n):")).lower() == 'y':call(["apt-get", "install", "nautilus-actions"])
    else:
        print("Can't keep going!")
        exit()


class window(Gtk.Window):
    '''UI Config Class for subseeker installer.
    '''
    def __init__(self):
        Gtk.Window.__init__(self,title="Setup Subseeker")
        #Gtk UI Coinfig Class
        self.set_border_width(10)
        self.listbox = Gtk.ListBox()
        self.listbox.set_selection_mode(Gtk.SelectionMode.NONE)
        self.add(self.listbox)
        self.set_default_size(300,300)
        self.set_resizable(False)
        #Calling UI-Functions
        self.headings();self.user_input_dialouges();self.action_buttons()

    def headings(self):
        #Heading Stuff
        self.heading_text = Gtk.Label('''Welcome to Subseeker Setup Utility\n\nPlease Login with your Opensubtitles\n credentials to use Subseeker.\n''')
        self.heading_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=10)
        self.heading_box.pack_start(self.heading_text,1,1,0)
        self.heading_box.set_center_widget(self.heading_text)
        self.listbox.add(self.heading_box)
        
    def user_input_dialouges(self):
        #Username Input Field
        self.username_row = Gtk.ListBoxRow()
        self.username_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=0)
        self.username_row.add(self.username_box)
        self.username_label = Gtk.Label("Username/Email:")
        self.username_entry = Gtk.Entry()
        self.username_box.pack_start(self.username_label,1,1,10)
        self.username_box.pack_start(self.username_entry,1,1,10)
        self.listbox.add(self.username_row)
        #Password Input Field
        self.password_row = Gtk.ListBoxRow()
        self.password_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=10)
        self.password_row.add(self.password_box)
        self.password_label = Gtk.Label("Password:")
        self.password_entry = Gtk.Entry()
        self.password_entry.set_visibility(False)
        self.password_box.pack_start(self.password_label,1,1,10)
        self.password_box.pack_start(self.password_entry,1,1,10)
        self.listbox.add(self.password_row)
        #Toggle Switch for 3rd party Search, This Feature is currently not implimented.
        self.switch_row = Gtk.ListBoxRow()
        self.switch_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=10)
        self.switch_row.add(self.switch_box)
        self.switch_label = Gtk.Label("Search third party sites as well:")
        self.switch_entry = Gtk.Switch()
        self.switch_box.pack_start(self.switch_label,1,1,10)
        self.switch_box.pack_start(self.switch_entry,1,1,10)
        self.listbox.add(self.switch_row)
        #List box for language Selection
        self.lang_row = Gtk.ListBoxRow()
        self.lang_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=10)
        self.lang_row.add(self.lang_box)
        self.lang_label = Gtk.Label("Select Your Default Language:")
        self.lang_combo = Gtk.ComboBoxText()
        with open('lang_pack.csv','r') as languages:
            languages = languages.read().split('\n')
            languages = [i.split(',')[1] for i in languages if len(i) > 1]
        for i,j in enumerate(languages):self.lang_combo.insert(i,str(i),j)
        self.lang_box.pack_start(self.lang_label,1,1,10)
        self.lang_box.pack_start(self.lang_combo,1,1,10)

        self.listbox.add(self.lang_row)
    def action_buttons(self):
        #Submit Button for stuff and things
        self.submit_row = Gtk.ListBoxRow()
        self.submit_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=10)
        self.submit_row.add(self.submit_box)
        self.submit_button = Gtk.Button(label="Save Settings")
        self.submit_button.connect("clicked", self.submit_handle)
        self.submit_box.pack_start(self.submit_button,1,1,10)
        self.listbox.add(self.submit_row)
        
    def submit_handle(self,widget):
        #Handles all Operations after Submit is Called
        if not( self.username_entry.get_text() and self.password_entry.get_text() and self.lang_combo.get_active_text()):
            print("Please fill empty fields before submitting.!")
            return
        self.destroy()
        print("Installation in Progress..")
        print("Processing User Configs.")
        with open('lang_pack.csv') as lang_code:
            lang_code = lang_code.read().split('\n')
            lang_code = dict( [i.split(',')[::-1] for i in lang_code if len(i) > 1])
        username,password,default_lang = [self.username_entry.get_text(),self.password_entry.get_text()
                                          ,lang_code[self.lang_combo.get_active_text()]]
        print("Processing User Configs: OK!")
        print("Writing User Configs.")
        with open('usr_config.ini','w') as file_handle:
            file_handle.write('%s|%s|%s'%(username,password,default_lang))
        print("Writing User Configs: OK!")
        print("Copying Files......")
        cwd = os.getcwd()
        try:os.mkdir(os.path.expanduser('~')+'/.subseeker/')
        except:print("Directory Already exists!")
        call(['cp',cwd+'/subseeker.py',os.path.expanduser('~')+'/.subseeker/'])
        print("Copying Config Files...")
        time.sleep(2)
        call(['cp',cwd+'/usr_config.ini',os.path.expanduser('~')+'/.subseeker/'])
        print("Copying  Files:OK!")
        time.sleep(2)
        print("Installation completed , Opening readme....")
        self.launch_readme()
        
    def launch_readme(self):
        f = open(os.path.expanduser('~')+'/readme.txt','w')
        f.write(string)
        f.close()
        call(["gedit",os.path.expanduser('~')+'/readme.txt'])
        return
        
    def dummy(self,widget):
        print("Callback test for %s widget!"%widget)
        return

string = '''
 Subseeker 2v2  \n Installation complete , just one step from here and we're ready to go!

 \n * Open Nautilus Action Config Tool for the Search Bar.
 \n * Select "Tools" from the top toolbar of Nautilus Action Config Tool.
 \n * Select "Import assistant" from the Dropdown Menu.
 \n * A New window will open , Click "Next" in it. , A file selection window appears.
 \n * Navigate it to the main extracted folder (Where you extrated the Compressed Archive).
 \n * Select the config file (Named Like:config_67db8ea9"".schemas) and Comple the Import.
 \n * Click the save Icon (Just left of Red off button) and if anything prompts , click "Yes".
 \n * Restart the Computer.
 \n * Delete the extracted Archive to save disk space.
 \n * Delete the "subseeker" folder and the readme file you extracted to save disk space.
 \n\n                        ** Test Installation. **
 \n * Navigate to a video file , In the third last row click "Nautilus Actions" and Then "Get Subs".
 \n * The Subtitle will be Automatically Downloaded in the same folder as Video.
 \n * Enjoy! '''
if __name__ == "__main__":
    root = window()
    root.connect("delete-event", Gtk.main_quit)
    root.show_all()
    Gtk.main()
