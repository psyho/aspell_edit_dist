$LOAD_PATH << File.expand_path( File.dirname(__FILE__) + '/../ext' )
$LOAD_PATH << File.expand_path( File.dirname(__FILE__) + '/..' )

require 'test/unit'

system("cd #{File.expand_path(File.join(File.dirname(__FILE__), '..'))}; make distclean")

system("cd #{File.expand_path(File.join(File.dirname(__FILE__), '..'))}; ruby ext/extconf.rb")
system("cd #{File.expand_path(File.join(File.dirname(__FILE__), '..'))}; make")

require "aspell_edit_dist"