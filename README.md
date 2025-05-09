# ExtremeSidechain
ExtremeSidechain is a simple and free VST plugin effect that does ring mod sidechaining. It's a very lightweight VST with no UI, you simply add it to the track you want to sidechain, add your sidechain input, and it will do ring mod sidechaining.


## Installation Guide
Installing this VST is very straightforward. Go to the [Releases](https://github.com/KaixoCode/ExtremeSidechain/releases) tab, select the latest release, and simply download the ZIP file for your OS. Then extract the ZIP, it should contain a file/folder named `ExtremeSidechain.vst3`, put that in your VST3 folder, which is usually located somewhere like `C:\Program Files\Common Files\VST3`.

### For MacOS users
You cannot use the Mac version without some workaround. If you install it like usual, it will tell you it's not safe, and it will prevent you from using it. I would need to sign the VST using an Apple Developer account, but I simply don't have access to a Mac device, or an Apple Developer account... There is a workaround, simply extract the ZIP for Mac like normal, and then run this command `xattr -d -r com.apple.quarantine '/Library/Audio/Plug-Ins/VST3/ExtremeSidechain.vst3'` BEFORE your DAW scans for new plugins. I know this isn't ideal, but sincerely, fuck Mac.

## Questions
If you have any troubles, questions or suggestions about this plugin you can contact me on Discord `@kaixo`.
