call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsx86_amd64.bat 
set CL=/DBOOTTEST
msbuild C:\Jenkins\workspace\TestPipeline\JenkinsTestBuild\ /t:rebuild
