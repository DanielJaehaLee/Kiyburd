# Kiyburd

**Split 40% ortholinear diode-less mechanical keyboard**

Kiyburd is a hand-designed split keyboard built around a 44-key ortholinear grid, direct-pin wiring (no diode matrix), and a pair of Raspberry Pi Picos talking over TRRS. The goal is a compact, stabilizer-free board that is easier to wire and firmware-tune than a conventional matrix keyboard, without giving up QMK features.

![Kiyburd layout](keyboard%20layout/keyboard-layout.png)

| | |
|---|---|
| **Form factor** | Split 40% · 22 keys per half · 44 keys total |
| **Grid** | Ortholinear 1u keys · no stabilized keys |
| **Scanning** | Direct GPIO (diode-less / matrix-less) |
| **MCU** | Raspberry Pi Pico (RP2040) × 2 |
| **Inter-half link** | TRRS (PJ-320A) · full-duplex USART |
| **Firmware** | [QMK](https://qmk.fm/) |
| **PCB** | Reversible KiCad design (same board for left and right) |
| **Status** | PCB designed and ordered · QMK port working · case and Vial still open |

---

## Why this layout

Most 40% boards still carry a row/column matrix, diodes, and at least a few 2u keys that need stabilizers. Kiyburd drops those on purpose:

- **Split 40%** keeps the hands apart and the keymap small enough that layers do the work of a full-size board.
- **Ortholinear 1u grid** removes stagger and every stabilizer. Every switch is the same Cherry MX footprint.
- **Direct wiring** maps each switch to its own RP2040 GPIO. No diodes, no shared rows/columns, no ghosting to design around.
- **Reversible PCB** means one Gerber set builds both halves.

The default firmware keymap is QWERTY with three extra layers (function keys, numbers/arrows, symbols/nav). The files under `keyboard layout/` also document an experimental layered map with Hangul legends.

---

## Repository layout

```
Kiyburd/
├── Firmware/                 QMK keyboard definition
│   ├── config.h              RP2040 bootloader + USART pins
│   ├── info.json             Matrix pins, USB IDs, layout geometry
│   ├── kiyburd.h             LAYOUT() macro
│   ├── rules.mk              RP2040 + split keyboard
│   └── keymaps/default/      QWERTY + Lower / Raise / Raise2
├── PCB/Kiyburd/              KiCad 7/8 project
│   ├── Kiyburd.kicad_sch
│   ├── Kiyburd.kicad_pcb
│   └── production/           BOM, CPL, Gerbers (Kiyburd.zip)
└── keyboard layout/          Keyboard Layout Editor JSON / SVG / PNG
```

---

## Hardware

### Bill of materials (per half)

| Qty | Part | Notes |
|----:|------|--------|
| 1 | Raspberry Pi Pico (RP2040) | Socket or solder; USB-C or Micro-USB depending on Pico revision |
| 1 | PJ-320A TRRS jack | Inter-half serial + GND |
| 22 | Cherry MX compatible switches | 5-pin preferred; footprint is `SW_Cherry_MX_1.00u_PCB_reversible` |
| 22 | 1u keycaps | No 2u / no stabs |
| 1 | TRRS cable | Tip-ring-ring-sleeve; not a TRS headphone cable |

Build two halves. The PCB is reversible: the Pico and TRRS footprints are placed so the same board works as left or right.

### Direct-pin map

Each switch is wired to one GPIO. Left and right halves mirror each other.

**Left half**

| Row | Col 0 | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 |
|-----|-------|-------|-------|-------|-------|-------|
| 0 | GP7 | GP6 | GP5 | GP4 | GP3 | GP2 |
| 1 | GP13 | GP12 | GP11 | GP10 | GP9 | GP8 |
| 2 | GP22 | GP26 | GP27 | GP28 | GP15 | GP14 |
| 3 | GP18 | — | — | GP19 | GP20 | GP21 |

**Right half**

| Row | Col 0 | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 |
|-----|-------|-------|-------|-------|-------|-------|
| 0 | GP2 | GP3 | GP4 | GP5 | GP6 | GP7 |
| 1 | GP8 | GP9 | GP10 | GP11 | GP12 | GP13 |
| 2 | GP14 | GP15 | GP28 | GP27 | GP26 | GP22 |
| 3 | GP21 | GP20 | GP19 | — | — | GP18 |

Split serial is full-duplex USART on the Pico's vendor serial driver:

| Signal | Pin |
|--------|-----|
| TX | GP1 |
| RX | GP0 |

Handedness defaults to left-as-master. Uncomment `#define MASTER_RIGHT` in `Firmware/config.h` if the right half should own USB.

### Ordering the PCB

Gerbers and assembly files live in `PCB/Kiyburd/production/`:

- `Kiyburd.zip` — Gerber/drill package
- `bom.csv` — bill of materials
- `positions.csv` — pick-and-place
- `designators.csv` / `netlist.ipc`

Open `PCB/Kiyburd/Kiyburd.kicad_pro` in KiCad to edit the board before re-exporting.

---

## Firmware

Firmware is a QMK keyboard named `kiyburd`. It targets the RP2040 bootloader and enables Bootmagic, extra keys, mouse keys, and NKRO.

### Features (`info.json`)

- `bootmagic`, `extrakey`, `mousekey`, `nkro`
- USB VID `0xFEED` / PID `0x0000` / device version `1.0.0` (change these before sharing boards)
- Double-tap reset on the Pico (`RP2040_BOOTLOADER_DOUBLE_TAP_RESET`, 1000 ms window)

### Build

After [setting up QMK](https://docs.qmk.fm/#/newbs):

```sh
# drop this folder into qmk_firmware/keyboards/kiyburd
make kiyburd:default
make kiyburd:default:flash
```

Or with the QMK CLI:

```sh
qmk compile -kb kiyburd -km default
qmk flash -kb kiyburd -km default
```

Copy the contents of `Firmware/` to `qmk_firmware/keyboards/kiyburd/` so the make target matches the documented name.

### Enter the bootloader

1. **Bootmagic** — hold the matrix `(0, 0)` key (Tab on the default map) and plug in USB.
2. **Double-tap reset** — tap the Pico RESET button twice within one second.
3. **Bootsel** — hold BOOTSEL on the Pico, plug in USB, then drop the `.uf2` onto the RPI-RP2 drive.

### Default keymap

Four layers. Modifiers stay on the home row edges; `MO(1)` / `MO(2)` / `MO(3)` sit on the inner thumb cluster.

```
Layer 0 — QWERTY
,-----------------------------------------.     ,-----------------------------------------.
| Tab  |  Q   |  W   |  E   |  R   |  T   |     |  Y   |  U   |  I   |  O   |  P   | Bksp |
| Ctrl |  A   |  S   |  D   |  F   |  G   |     |  H   |  J   |  K   |  L   |  ;   |  '   |
| Shift|  Z   |  X   |  C   |  V   |  B   |     |  N   |  M   |  ,   |  .   |  /   |  \   |
| Alt  |           | GUI |Lower| Space |     |Raise|Raise2| RAlt |           | Enter|
`-----------------------------------------'     `-----------------------------------------'

Layer 1 — Lower          function keys on the right hand
Layer 2 — Raise          1–0, ` - = [ ], arrows
Layer 3 — Raise2         shifted symbols, Home / Ins / Del / End
```

Edit `Firmware/keymaps/default/keymap.c` to change layers. The Keyboard Layout Editor sources in `keyboard layout/` are a good place to mock a new map before touching C.

---

## Build notes

1. Fabricate two PCBs from `PCB/Kiyburd/production/Kiyburd.zip`.
2. Solder the Pico and TRRS jack. Because the footprints are reversible, decide handedness before soldering if you are not using sockets.
3. Solder 22 MX switches per half. There are no diodes.
4. Flash QMK to both Picos.
5. Join the halves with a TRRS cable. Plug USB into the master half only.
6. Confirm every key in a matrix tester, then cap the board.

There is no case in this repo yet. The housing work is still an open milestone (FreeCAD).

---

## Project status

| Area | State |
|------|--------|
| KiCad proficiency / PCB design | Done |
| PCB ordered | Done |
| Direct-switch and split-link electrical design | Done |
| QMK port | Done |
| Vial | Not started |
| Case / FreeCAD | Not started |

---

## References

Designs that informed the brief:

- [Budgy](https://github.com/doesntfazer/Budgy) — Pico-powered split, diode-less
- [Cantor](https://github.com/diepala/cantor) — 42-key diode-less split
- [Chiron](https://github.com/qmk/qmk_firmware/blob/master/keyboards/handwired/chiron/keymaps/default/keymap.c)
- [Dactyl Manuform](https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/dactyl_manuform)

Docs:

- [QMK getting started](https://docs.qmk.fm/#/newbs)
- [QMK split keyboard](https://docs.qmk.fm/#/feature_split_keyboard)
- [RP2040 on QMK](https://docs.qmk.fm/#/platformdev_rp2040)

---

## License

Firmware sources carry `SPDX-License-Identifier: GPL-2.0-or-later` (QMK). Hardware files in `PCB/` do not declare a license yet — treat them as all-rights-reserved unless a license is added.

Maintainer: [DanielJaehaLee](https://github.com/DanielJaehaLee)
