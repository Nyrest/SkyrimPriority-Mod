# Skyrim Priority [![GitHub](https://img.shields.io/github/license/BThree496/SkyrimPriority-Mod?style=flat-square&logo=github)](https://github.com/BThree496/SkyrimPriority-Mod/blob/main/LICENSE)
<img src="./SkyrimPriority.png" alt="logo" width="70%" height="70%"/>

Tired of setting priority manually everytime after game startup?   
Many modern games will set their priority to `High` automatically like Assassin's Creed, Watch Dogs ..etc  
It ensured the game **always take most of CPU usage, prevent suddenly lag caused by other processes**.  
Now Skyrim can do the same  

Kick other processes out. Skyrim is the only one who should have whole CPU.
Be a wonder chicken Rude and Unreasonable.

## Priorities
|     Priority | Value | 
|------------- |------ |
| Idle         | 64    |
| Below Normal | 16384 |
| Normal       | 32    |
| Above Normal | 32768 |
| High         | 128   |
| Realtime     | 256   |

> SkyrimPriority uses `High` by default  
> You can change it in `SkyrimPriority.toml`

> `Realtime` require run SKSE as Administrator

## Note
### About `Realtime` Priority
https://docs.microsoft.com/en-us/windows/win32/procthread/scheduling-priorities#priority-class
>You should almost never use `Realtime`, because this interrupts system threads that manage mouse input, keyboard input, and background disk flushing. This class can be appropriate for applications that "talk" directly to hardware or that perform brief tasks that should have limited interruptions.
