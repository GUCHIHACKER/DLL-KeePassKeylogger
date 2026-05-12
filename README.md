# KeePass DLL Hijacking — Keylogger

A DLL hijacking proof-of-concept targeting **KeePass 2.x and KeePassXC**. The malicious DLL masquerades as `bcrypt.dll` and hooks `ToUnicodeEx` via [MinHook](https://github.com/TsudaKageyu/minhook) to capture keystrokes typed inside KeePass.

## How it works

1. **DLL Proxying** — All original `bcrypt.dll` exports are forwarded to `C:\Windows\System32\bcrypt.dll`, so KeePass loads normally.
2. **API Hooking** — On load, `DLL_PROCESS_ATTACH` uses MinHook to intercept `ToUnicodeEx`.
3. **Keylogging** — Each keystroke is logged with timestamp, virtual key code, translated character, active window title, and modifier state to:

   ```
   C:\Users\<USERNAME>\AppData\Local\Temp\wct3C3F97.tmp
   ```
  
5. **String obfuscation** — Sensitive strings are wrapped with `OBF()` macros from `obfusheader.h` to evade static analysis.

## Build

- Visual Studio 2019+ (x64)
- Requires `minhook.x64.lib` in `Keepass_dll/lib/`

## Usage

Replace `bcrypt.dll` in the KeePass directory with the compiled DLL. On next launch, keystrokes will be silently logged.

> **Note:** Write permissions to the KeePass installation directory are required to place the DLL alongside the executable. This is typically `C:\Program Files\KeePass Password Safe 2\` (KeePass 2.x) or `C:\Program Files\KeePassXC\` (KeePassXC).


## License

This project is licensed under the [Creative Commons Attribution 4.0 International (CC BY 4.0)](LICENSE) license.

You are free to use, share, and adapt this project **as long as you give appropriate credit** to the original author. See [LICENSE](LICENSE) for full terms.
