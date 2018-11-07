pipeline {
  agent any
  stages {
    stage('Fetch Repo') {
      steps {
        git 'https://github.com/SweeneyPro/JenkinsTestBuild.git'
      }
    }
    stage('Compile') {
      steps {
        bat(script: 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\JenkinsTestBuild\\CompileBatch.bat', returnStatus: true, returnStdout: true)
      }
    }
    stage('Run Boot Stages') {
      parallel {
        stage('Boot Stage 1') {
          steps {
            bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\x64\\Debug\\JenkinsTestBuild.exe BootStage1'
          }
        }
        stage('Boot Stage 2') {
          steps {
            bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\x64\\Debug\\JenkinsTestBuild.exe BootStage2'
          }
        }
        stage('Boot Stage 3') {
          steps {
            bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\x64\\Debug\\JenkinsTestBuild.exe BootStage3'
          }
        }
        stage('Boot Stage 4') {
          steps {
            catchError() {
              bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\x64\\Debug\\JenkinsTestBuild.exe BootStage4'
            }

          }
        }
        stage('Boot Stage 5') {
          steps {
            bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\x64\\Debug\\JenkinsTestBuild.exe BootStage5'
          }
        }
      }
    }
    stage('TestResults') {
      steps {
        livingDocs(numbered: true, sectAnchors: true, toc: 'CENTER', format: 'HTML')
      }
    }
  }
}